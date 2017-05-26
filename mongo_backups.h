#!/bin/sh
MONGO_DATABASE="spotasap"
APP_NAME="spotsoon"


MONGO_HOST="127.0.0.1"
MONGO_PORT="27017"
TIMESTAMP=`date +%F-%H%M`
MONGODUMP_PATH="/var/www/html/prasanna/"
BACKUPS_DIR="/var/www/html/prasanna/"
BACKUP_NAME="$APP_NAME-$TIMESTAMP"


# mongo admin --eval "printjson(db.fsyncLock())"
#$MONGODUMP_PATH -h $MONGO_HOST:$MONGO_PORT -d $MONGO_DATABASE
$MONGODUMP_PATH -d $MONGO_DATABASE
# mongo admin --eval "printjson(db.fsyncUnlock())"
mongodump -h $MONGO_HOST -d $MONGO_DATABASE -o $BACKUPS_DIR$BACKUP_NAME
gzip -f $BACKUPS_DIR$BACKUP_NAME
#mkdir -p $BACKUPS_DIR
#mv dump $BACKUP_NAME
tar -zcvf $BACKUPS_DIR/$BACKUP_NAME.tgz $BACKUP_NAME
rm -rf $BACKUPS_DIR$BACKUP_NAME
