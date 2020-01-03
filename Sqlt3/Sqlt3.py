import sqlite3

def Database():
    global conn, cursor
    conn = sqlite3.connect("db_admins.db")
    cursor = conn.cursor()
    cursor.execute( "CREATE TABLE IF NOT EXISTS `admins` (mem_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, username TEXT, password TEXT, age TEXT)")
    cursor.execute("CREATE TABLE IF NOT EXISTS `players` (username TEXT PRIMARY KEY  NOT NULL, password TEXT, age TEXT,score INTEGER,games INTEGER,date TEXT)")
    cursor.execute("CREATE TABLE IF NOT EXISTS `companion` (username TEXT PRIMARY KEY  NOT NULL, password TEXT, age TEXT,first TEXT,seconde TEXT)")

def insert_admin(username,password,age):
    cursor.execute("INSERT INTO `admins` (username, password, age) VALUES(?, ?, ?)",(username,password,age))
    conn.commit()

def insert_player(username,password,age):
    date_object = datetime.date.today()
    cursor.execute("INSERT INTO `players` (username, password, age,score,games,date) VALUES(?, ?,?,?,?,?)", (username,password,age,0,0,str(date_object)))
    conn.commit()

def insert_companion(username,password,age,first,seconde):
    cursor.execute("INSERT INTO `companion` (username, password, age,first,seconde) VALUES(?, ?,?,?,?)", (username,password,age,first,seconde))
    conn.commit()

def deletePlayer(name):
    cursor.execute("delete from players where username= ?", (name,))
    conn.commit()

def AddScore(name):
    cursor.execute("SELECT * FROM players WHERE username=?", (name,))
    rows = cursor.fetchall()
    score=rows[0][3]
    score+=1
    cursor.execute('UPDATE players SET score = ? WHERE username =?',(score,name,))
    conn.commit()

def AddGame(name):
    cursor.execute("SELECT * FROM players WHERE username=?", (name,))
    rows = cursor.fetchall()
    game=rows[0][4]
    game+=1
    cursor.execute('UPDATE players SET games = ? WHERE username =?',(game,name,))
    conn.commit()

def PrintDB():
    cursor.execute("SELECT * FROM players WHERE username=?", (name,))
    rows = cursor.fetchall()
    for i in rows:
        print(i)
