#ifndef SERVERLIBRARY_H
#define SERVERLIBRARY_H

// Libraries
#include "client.h"
#include <iostream>

using namespace std;

/**
 * @brief The Server Library allows multiple clients to access the information of
 * My invincible library. Communicating in a simple way MyIDE with RAID Library
 * and Metadata DB.
 */
class ServerLibrary
{
public:

    /**
     * @brief It is responsible for creating a single instance of ServerLibrary
     * @brief ** Implements the Singleton design pattern.
     * @return An instance of ServerLibrary
     */
    static ServerLibrary* getServer();

    // Interface that connects GUI with RAID and METADATA DATABASE

    /**
     * @brief It is responsible for inserting new images in the RAID and in the
     * metadata Database
     * @param MetaJson[in] :Receive a JSON that contains the metadata of the image
     * @return void
     */
    void INSERT(QString MetaJson);

    /**
     * @brief Method in charge of returning a JSON with the requested image from
     * the client, under the criterion of the parameters of the metadata
     * @param MetaJson[in] : Receive a json with the information of the requested image
     * @return [out] : Returns the requested image and metadata in JSON format
     */
    QString SELECT(QString MetaJson);

    /**
     * @brief Update the metadata of an image or several images
     * @param MetaJson[in] : Receive a json with the information of the requested image
     * @return void
     */
    void UPDATE(QString MetaJson);

    // The delete receives metada but it is in charge of connecting
    // with both web services to complete the action
    /**
     * @brief Method responsible for removing an image from the disk given its metadata
     * @param MetaJson[in] : Receive a json with the information of the requested image
     * @return void
     */
    void DELETE(QString MetaJson);

    /**
     * @brief Make commit of all changes made to the database
     */
    void COMMIT();

    /**
     * @brief Make Rollback of all changes made to the database
     */
    void BACK();

    // Configuration of the necessary information for the connection
    void setRaid(QString url,QString ip = "localhost",QString port = "9080");
    void setMilib(QString url,QString ip = "localhost",QString port = "8080");

    // Returns and prints API information on the screen
    void getRaidInfo();
    void getMilibInfo();
private:

    static ServerLibrary* server;

    // MILIB :: information necessary for connection to the web service
    QString MilibIP;
    QString MilibPort;
    QString MilibUrl;

    // RAID :: information necessary for connection to the web service
    QString RaidIP;
    QString RaidPort;
    QString RaidUrl;

    ServerLibrary();
};

#endif // SERVERLIBRARY_H
