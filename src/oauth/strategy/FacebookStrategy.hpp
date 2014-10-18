/*
 * For more information on the Facebook OAuth process:
 *      https://developers.facebook.com/docs/facebook-login/manually-build-a-login-flow/v2.1
 *
 * Created on: 18-okt.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */
#ifndef FACEBOOKSTRATEGY_HPP_
#define FACEBOOKSTRATEGY_HPP_

#include <QNetworkAccessManager>
#include <QNetworkRequest>

#include "OAuthStrategy.hpp"


namespace oauth {
    namespace strategy {

        class FacebookStrategy: public OAuthStrategy
        {
            Q_OBJECT

            private:
                QNetworkAccessManager* networkManager;

            public:
                FacebookStrategy(QObject *parent=0);

                QUrl getAuthorizationUrl() const;

            private slots:
                void handleRequest(WebNavigationRequest *request);
                void onAccessTokenRetrieved(QNetworkReply *reply);
        };

    } /* namespace strategy */
} /* namespace oauth */

#endif /* FACEBOOKSTRATEGY_HPP_ */
