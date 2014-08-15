/*
 * OAuth.hpp
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef OAUTH_HPP_
#define OAUTH_HPP_

#include <QObject>
#include <bb/cascades/WebView>

#include "OAuthStrategy.hpp"

using namespace bb::cascades;
using namespace oauth::strategy;

namespace oauth {

    class OAuth : public QObject
    {
        Q_OBJECT

        private:
            OAuthStrategy *strategy;
            QString accessToken;

        public:
            OAuth(QObject *parent=0);

            QString getAccessToken() const;

            void setStrategy(OAuthStrategy *strategy);
            void authorize(WebView *webview);

        private slots:
            void accessTokenRetrieved(const QString& token);

        signals:
            void authorized();
    };

} /* namespace oauth */
#endif /* OAUTH_HPP_ */
