/*
 * OAuthStrategy.cpp
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include <QUuid>

#include "OAuthStrategy.hpp"

namespace oauth {
    namespace strategy {

        OAuthStrategy::OAuthStrategy(QObject *parent) : QObject(parent) {
            this->setRedirectUrl(QUrl("http://localhost"));

            // Generate a unique state that can be used to prevent CSRF
            this->state = QUuid::createUuid().toString().remove(QRegExp("\\W"));
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

        void OAuthStrategy::setRedirectUrl(const QUrl& redirectUrl) {
            this->redirectUrl = redirectUrl;
        }

        QUrl OAuthStrategy::getRedirectUrl() const {
            return this->redirectUrl;
        }

        void OAuthStrategy::setScope(const QString& scope) {
            this->scope = scope;
        }

        QString OAuthStrategy::getScope() const {
            return this->scope;
        }

        QString OAuthStrategy::getState() const {
            return this->state;
        }

    } /* namespace strategy */
} /* namespace oauth */
