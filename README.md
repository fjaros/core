These instructions are how to compile and run this MaNGOS fork on Linux, specifically Ubuntu 18.04 Server distro. It was the least resistant distro in terms of compilation.

-- DOWNLOAD AND DISTRO SETUP:
1) Install Ubuntu 18.04 LTS Server.

2) Install updates, dependencies, and give it a good ole reboot after:
`sudo apt-get update && sudo apt-get upgrade && sudo apt install build-essential cmake libace-dev libtbb-dev mariadb-server mariadb-client libmysqlclient-dev libssl1.0-dev unrar p7zip-full && sudo reboot`

3) Although we will use the source from this repo we need the game files for the server so need to download/transfer the latest Lights Hope repack on the server. Currently https://www.mediafire.com/file/is1uobq3fjcza1h/Lights+Hope+bropack+v11.rar

-- COMPILE:
4) Clone this repo `git clone https://github.com/fjaros/core` 

5) `cd theconstruct`

6) `cmake . && make`
This will take about half an hour to compile
And will produce two key binaries: `src/realmd/realmd` and `src/mangosd/mangosd`

7) Move these files to the directory where you want to run your server

8) Go back and unrar Lights Hope bropack (the full download from earlier) - we will only use the data and config files from here.
Move files `MaNGOS/realmd.conf` and `MaNGOS/mangosd.conf` to the same folder as above
Move directories `MaNGOS/data` and `MaNGOS/logs` to the same folder as above

-- SETUP DATABASE: (secure/setup your mariadb/mysql however you like first)
9) `sudo mysql`
If you do not care to setup your mysql securely, you can just run:
`grant all privileges on *.* to 'root'@'localhost' identified by 'root';`

!!! DISCLAIMER: THIS IS EXTREMELY UNSECURE AND WILL GET YOUR SERVER HACKED. DO NOT DO THIS. !!!

10) `create database characters; create database mangos; create database logs; create database realmd;`
\q

11) `cd MaNGOS/sql`

12) `7z x FULL_WORLD_DB_19_06_2018.7z` - (or whatever the name may be)

13) `sudo mysql -uroot mangos < FULL_WORLD_DB_19_06_2018.sql` (or whatever you set the mysql user as)

14) `cd Base`

15) `sudo mysql -uroot characters < characters.sql && sudo mysql -uroot realmd < logon.sql && sudo mysql -uroot logs < logs.sql`

16) `sudo mysql`
```
INSERT INTO realmd.realmlist (id, name, address, port, icon, realmflags, timezone, allowedSecurityLevel) VALUES (
	1, 'your_server_name', 'your_external_ip', 8085, 1, 0, -9, 1
)
```

IMPORTANT: the address 'your_external_ip' is the IP users will use to connect to the server. it is the EXTERNAL IP of your server.

-- SETUP SERVER:
16) Go to the folder where you moved the compiled files
17) Open realmd.conf, you will see line
`LoginDatabaseInfo = "127.0.0.1;3306;root;root;realmd"`
Change the `root;root` to be your mysql username and password . if you did not secure your mysql you can keep it as is.
Change line `LogsDir = "logs\"` to `LogsDir = "logs/"`
Everything else can be kept the same here

19) Open mangosd.conf
Again scroll down and look at the mysql connection strings. Make sure the user/password is correct.

Change `LogsDir = "logs\"` to `LogsDir = "logs/"`
Change `DataDir = "data\"` to `DataDir = "data/"`

Everything else can be kept the same, but you can modify any server-specific settings in this file. For example rate of XP gain, or how much money each character starts with.

-- RUN SERVER:
20) Finally we need to run everything!
First make sure both components work. First we'll run the login server:

Run: ./realmd -c realmd.conf
If it starts successfully you should see this output:
```
mangos@wow:~/build$ ./realmd -c realmd.conf
Core revision: unknown / 1970-01-01 00:00:00 +0000 / Linux_x64 (little-endian) [realm-daemon]
<Ctrl-C> to stop.

Using configuration file realmd.conf.
Max allowed open files is 1024
Database: 127.0.0.1;3306;root;root;realmd
Added realm "your_server_name"
```

Now you can CTRL+C out of it and run it in the background. For instance via: nohup ./realmd -c realmd.conf &

Now we'll run the game server:
./mangosd -c mangosd.conf
If it starts successfully you should see this output or similar:
```
==========================================================
Current content is set to Patch 1.12: Drums of War.
==========================================================

World initialized.
SERVER STARTUP TIME: 0 minutes 3 seconds
Max allowed socket connections 1024

mangos>
>> Only expired mails (need to be return or delete) or DB table `mail` is empty.
```

Now you can create your account!
Type: account create <username> <password>
(replacing <username> and <password> with your login information)

And you can set this account to be highest admin via:
account set gmlevel <username> 6

CLIENT:
In the WoW 1.12 client you downloaded should be a file called realmlist.wtf. Open this file in a text editor and delete everything. Then input `set realmlist <external_ip>` where <external_ip> is the IP of your server and MUST be the same as the one you input to the SQL command in step 16.

And that's all! Have fun!
