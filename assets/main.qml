import bb.cascades 1.0

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
