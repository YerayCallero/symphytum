/**
  * \class SyncConfigDialog
  * \brief This dialog is used to configure a cloud sync service.
  * \author Giorgio Wicklein - GIOWISYS Software
  * \date 11/08/2012
  */

#ifndef SYNCCONFIGDIALOG_H
#define SYNCCONFIGDIALOG_H


//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------

#include <QtGui/QDialog>


//-----------------------------------------------------------------------------
// Forward declarations
//-----------------------------------------------------------------------------

namespace Ui {
class SyncConfigDialog;
}

class AbstractSyncDriver;


//-----------------------------------------------------------------------------
// SyncConfigDialog
//-----------------------------------------------------------------------------

class SyncConfigDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SyncConfigDialog(QWidget *parent = 0);
    ~SyncConfigDialog();

    /**
     * Re-authenticate for the configured sync service.
     * This method should be called whenever sync methods
     * fail because of an expired token.
     */
    void reauthenticateSyncService();

private slots:
    void loginButtonClicked();
    void okButtonClicked();
    void finishButtonClicked();
    void retryButtonClicked();

    //sync slots
    /** Called if an error occurred */
    void syncError(const QString &message);

    /** Error, token expired */
    void syncErrorTokenExpired();

    /** Error, connection failed */
    void syncErrorConnectionFailed();

    /** Called on auth request completion */
    void syncUrlAuth(const QString &url);

    /** Called when auth validate request was successful */
    void syncAuthValidated();

    /** Called on user name request completion */
    void syncUserName(const QString &userName);
    
private:
    void init();
    void createConnections();
    void updateFinishButton(bool enabled);
    void createSyncConnections();

    Ui::SyncConfigDialog *ui;
    int m_syncService;
    AbstractSyncDriver *m_syncDriver;
};

#endif // SYNCCONFIGDIALOG_H
