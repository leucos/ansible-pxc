Percona server deployment
=========================

Percona playbook deployement

This role will let you install a Percona server.

Requirements
------------

MySQLdb python package (required by `mysql_*` Ansible modules)

Role Variables
--------------

Very few variables are in this role for now. It will grow as needed.

- `mysql_backup`: whether a regulard `mysqldump` should be made (default: unset)

    `mysql_backup`:
      `crontime`: [cronentry] cron entry that triggers the backup
      `keep`: [number] how many backups do we keep
      `destination`: [destination] directory in the filesystem to put backups in
      `s3bucket`: [bucketaddess] when defined, this will trigger a copy of backuped files to an S3 bucket

- `mysql_users`: list of users and privileges to add besides root (see `mysql_user` for reference; default: [])

    `mysql_users`:
      - { user: <username>,
          password: "<password>",
          priv="<privileges>", # (e.g. "*.*:ALL")
          host="<host>" # (host from which user connects)
         }

- `mysql_bind_address`: bind address (default: "127.0.0.1")
- `mysql_key_buffer`: buffer size for keys (default: "16M")
- `mysql_php5`: should we install mysql php5 extensions (default: false)
- `mysql_root_password`: root password (default: "changeme")

- `percona_version`: major.minor version to install (defaumt: "5.6")

Usage
-----

The role is supposed to be used this way from a playbook:

   - { role: leucos.mysql }

Dependencies
------------

This role depends on:
- [leucos.s3cmd](https://github.com/leucos/ansible-s3cmd) when S3 backup is enabled

License
-------

MIT

Author Information
------------------

[@leucos](https://github.com/leucos)
