#ifndef CHANNELMODEL_H
#define CHANNELMODEL_H

#include <QObject>
#include <QStringListModel>
#include "util.h"
#include "qobjectlistmodel.h"
#include "messagemodel.h"

class ChannelModel : public QObject
{
    Q_OBJECT

    GENPROPERTY(QString, _name, name, setName, nameChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    GENPROPERTY(QString, _currentMessage, currentMessage, setCurrentMessage, currentMessageChanged)
    Q_PROPERTY(QString currentMessage READ currentMessage WRITE setCurrentMessage NOTIFY currentMessageChanged)
    Q_PROPERTY(QObject* users READ users)
    Q_PROPERTY(int userCount READ userCount)

    QObjectListModel<MessageModel> _messages;
    QStringListModel _users;
    friend class IrcModel;

public:
    explicit ChannelModel(QString name = QString(), QObject *parent = 0);
    Q_INVOKABLE QObject *messages() { return &_messages; }
    Q_INVOKABLE QStringListModel *users() { return &_users; }
    Q_INVOKABLE int userCount() { return _users.rowCount(); }

signals:
    void nameChanged();
    void currentMessageChanged();

private slots:
    void fakeMessage();

public slots:
    void close();
    void sendCurrentMessage();

};

#endif // CHANNELMODEL_H
