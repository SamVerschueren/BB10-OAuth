/*
 * OAuthStrategy.hpp
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef OAUTHSTRATEGY_HPP_
#define OAUTHSTRATEGY_HPP_

#include <QObject>
#include <QUrl>
#include <bb/cascades/WebNavigationRequest>

using namespace bb::cascades;

namespace oauth {
    namespace strategy {

        class OAuthStrategy : public QObject
        {
            Q_OBJECT

            private:
                QString clientKey;
                QString clientSecret;
                QUrl callbackUrl;

            public:
                OAuthStrategy(QObject *parent=0);

                void setClientKey(const QString& clientKey);
                void setClientSecret(const QString& clientSecret);
                void setCallbackUrl(const QUrl& callbackUrl);

                virtual QUrl getAuthorizationUrl() const = 0;

            protected:
                QString getClientKey() const;
                QString getClientSecret() const;
                QUrl getCallbackUrl() const;

            private slots:
                virtual void handleRequest(bb::cascades::WebNavigationRequest *request)=0;

            signals:
                void accessTokenRetrieved(const QString& accessToken);
        };

    } /* namespace strategy */
} /* namespace oauth */
#endif /* OAUTHSTRATEGY_HPP_ */
