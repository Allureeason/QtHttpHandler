#ifndef __PROTOCOL_TEST_H__
#define __PROTOCOL_TEST_H__

#include "IHttpMsgBase.h"

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QDebug>

class HttpMsgTestReq : public HttpMsgRequest
{
public:
    HttpMsgTestReq() {}
    virtual ~HttpMsgTestReq() {}

    virtual void parseJson(const QString& json) override {
        QJsonDocument doc = QJsonDocument::fromJson(json.toLocal8Bit());
        if(doc.isEmpty() || !doc.isObject()) {
            qDebug() << "json:" << json << " invalid json object";
            return;
        }

        QJsonObject root = doc.object();
        auto data = root["data"].toObject();
        if(data.isEmpty()) {
            qDebug() << "data object:" << data << " invalid json object";
            return;
        }

        m_name = data["name"].toString();
        m_age = data["age"].toInteger();
    }

    virtual QString packJson() const override {
        QJsonObject obj;
        obj["name"] = m_name;
        obj["age"] = m_age;
        QJsonDocument doc(obj);
        return doc.toJson();
    }

    void setName(QString name) { m_name = name; }
    void setAge(int64_t age) { m_age = age; }

private:
    QString m_name;
    int m_age = 18;
};


#endif // __PROTOCOL_TEST_H__
