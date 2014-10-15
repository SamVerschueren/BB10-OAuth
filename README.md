BB10-OAuth
==========

To use the framework in your own project, just copy the src/oauth folder to your own project.

# Strategies
This framework uses strategies that are little modules that knows how to authenticate at a specific service like Google.

The strategies implemented are:
* Google
* GitHub
* LinkedIn

## Use a strategy

For instance, if you want to let your user authenticate with google, create a GoogleStrategy object and set
all the properties.

```C++
OAuthStrategy *google = new GoogleStrategy(this);
google->setClientKey("client_key");
google->setClientSecret("client_secret");
google->setScope("email profile");
```

Then you have to create an OAuth object and let it use that google strategy.

```C++
OAuth *oauth = new OAuth(this);
oauth->setStrategy(google);
```

# Redirect URI
Every service uses a redirect URI in order to provide a code that can be exchanged for an access token. The redirect URI will be intercepted
by the framework. By default, the redirect URI is http://localhost but it can be changed to something else.

```C++
strategy->setRedirectUrl("http://www.mydomain.com");
```

# Retrieve the access token
In order to start the authorization process of the user, you should call the authorize() method of the OAuth object and pass a webview
as parameter. This webview is used to show the sign in screen of the specific service.

In the example, you can see that we have a controller that is exposed to QML

```C++
qRegisterMetaType<QObject*>("WebView*");

QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
qml->setContextProperty("loginController", loginController);
```

IMPORTANT: The first line will make sure that the WebView* can be used by QMetaProperty. If you forget this line you will get an error indicating
that you have an unknown parameter type WebView*.

Now you can start the authorisation process in QML.

```QML
Page {
    Container {
        WebView {
            id: oauthWebview
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            settings.javaScriptEnabled: true;
            preferredHeight: Infinity
        }
    }
    
    onCreationCompleted: {
        loginController.authorize(oauthWebview);
    }
}
```

# Contributors
* Sam Verschueren	[sam.verschueren@gmail.com]

# MIT License
Copyright © 2014 Sam Verschueren <sam.verschueren@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
