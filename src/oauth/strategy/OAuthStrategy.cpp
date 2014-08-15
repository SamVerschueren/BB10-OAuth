/*
 * OAuthStrategy.cpp
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "OAuthStrategy.hpp"

namespace oauth {
    namespace strategy {

        OAuthStrategy::OAuthStrategy(QObject *parent) : QObject(parent) {
            this->setCallbackUrl(QUrl("http://localhost"));
        }

        void OAuthStrategy::setClientKey(const QString& clientKey) {
            this->clientKey = clientKey;
        }

        QString OAuthStrategy::getClientKey() const {
            if(this->clientKey.isEmpty()) {
                // Warn the developer that no client key was provided and that the user
                // will probably see a 404 Not found page.
                qWarning() << "OAuth:No client key provided.";
            }

            return this->clientKey;
        }

        void OAuthStrategy::setClientSecret(const QString& clientSecret) {
            this->clientSecret = clientSecret;
        }

        QString OAuthStrategy::getClientSecret() const {
            if(this->clientSecret.isEmpty()) {
                // Warn the developer that no client key was provided and that the user
                // will probably see a 404 Not found page.
                qWarning() << "OAuth:No client secret provided.";
            }

            return this->clientSecret;
        }

        void OAuthStrategy::setCallbackUrl(const QUrl& callbackUrl) {
            this->callbackUrl = callbackUrl;
        }

        QUrl OAuthStrategy::getCallbackUrl() const {
            return this->callbackUrl;
        }

    } /* namespace strategy */
} /* namespace oauth */
