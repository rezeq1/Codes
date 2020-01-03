import time
from builtins import range, open
from tkinter import *
from tkinter import ttk
import tkinter.messagebox as tkMessageBox
import sqlite3
from pygame import mixer
import datetime
import random
import webbrowser

date_object = datetime.date.today()

# creat window -----------------------------------------
windo = Tk()
windo.title("Link Game")
Question = PhotoImage(file="ques.png")
buttonImag = PhotoImage(file='rrr.png')
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


width =1060
height = 750
screen_width = windo.winfo_screenwidth()
screen_height = windo.winfo_screenheight()
x = (screen_width / 2) - (width / 2)
y = (screen_height / 2) - (height / 2)
windo.geometry("%dx%d+%d+%d" % (width, height, x, y))
windo.resizable(0, 0)
#############
mixer.init()

mixer.music.load('music.wav')
mixer.music.play()
HELPM = StringVar()
WINNER = StringVar()
HELPM.set("false")
COLORH = StringVar()
COLORH.set("light green")
def stop_():
    if HELPM.get() == "false":
        mixer.music.pause()
        HELPM.set("true")
    else:
        HELPM.set("false")
        mixer.music.unpause()

# ---------------------------------------------------------
def Database():
    global conn, cursor
    conn = sqlite3.connect("db_admins.db")
    cursor = conn.cursor()
    cursor.execute( "CREATE TABLE IF NOT EXISTS `admins` (mem_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, username TEXT, password TEXT, age TEXT)")
    cursor.execute("CREATE TABLE IF NOT EXISTS `players` (username TEXT PRIMARY KEY  NOT NULL, password TEXT, age TEXT,score INTEGER,games INTEGER,date TEXT)")
    cursor.execute("CREATE TABLE IF NOT EXISTS `companion` (username TEXT PRIMARY KEY  NOT NULL, password TEXT, age TEXT,first TEXT,seconde TEXT)")




COMPANION_NAME=StringVar()
COMPANION_PASSWORD=StringVar()
FIRST=StringVar()
LAST=StringVar()
TRACK_NAME=StringVar()
PLAYER1 = StringVar()
PLAYER2 = StringVar()
PLAYER3 = StringVar()
PASSWOR1 = StringVar()
PASSWOR2 = StringVar()
PASSWOR3 = StringVar()
USERNAME2 = StringVar()
PASSWORD2 = StringVar()
AGE2 = StringVar()

USERNAME = StringVar()
PASSWORD = StringVar()
AGE = StringVar()

def Choose_Account_Form():
    global Choose_AccountFrame
    Choose_AccountFrame = Frame(windo)
    Choose_AccountFrame.pack()

    lbl_ = Label(Choose_AccountFrame, text="", font=('arial', 18), bd=18)
    lbl_.grid(row=0)

    btn_companion = Button(Choose_AccountFrame, text="For Companions", font=('arial', 18), width=35,fg='purple', command=ChooseToCompanion)
    btn_companion.grid(row=2, columnspan=2, pady=20)

    btn_admin = Button(Choose_AccountFrame, text="For Admins", font=('arial', 18), width=35,fg='purple', command=ChooseToLogin)
    btn_admin.grid(row=5, columnspan=2, pady=20)





def RegisterPlayersForm():
    global RegisterPlayersFrame, lbl_result2

    RegisterPlayersFrame = Frame(windo)
    RegisterPlayersFrame.pack(side=TOP, pady=40)

    lbl_result_empty = Label(RegisterPlayersFrame, text="Register For Players", font=('arial', 18),fg="blue")
    lbl_result_empty.grid(row=0, columnspan=2)

    lbl_username = Label(RegisterPlayersFrame, text="Username:", font=('arial', 18), bd=18)
    lbl_username.grid(row=2)

    lbl_password = Label(RegisterPlayersFrame, text="Password:", font=('arial', 18), bd=18)
    lbl_password.grid(row=3)

    lbl_age = Label(RegisterPlayersFrame, text="Age:", font=('arial', 18), bd=18)
    lbl_age.grid(row=4)

    lbl_result2 = Label(RegisterPlayersFrame, text="", font=('arial', 18))
    lbl_result2.grid(row=6, columnspan=2)

    username = Entry(RegisterPlayersFrame, font=('arial', 20), textvariable=USERNAME2, width=15)
    username.grid(row=2, column=1)

    password = Entry(RegisterPlayersFrame, font=('arial', 20), textvariable=PASSWORD2, width=15, show="*")
    password.grid(row=3, column=1)

    age = Entry(RegisterPlayersFrame, font=('arial', 20), textvariable=AGE2, width=15)
    age.grid(row=4, column=1)

    btn_login = Button(RegisterPlayersFrame, text="Register", font=('arial', 18), width=35,fg='green', command=RegisterPlayers)
    btn_login.grid(row=7, columnspan=2, pady=20)

    btne_login = Button(RegisterPlayersFrame, text="Return To Login", fg="red", font=('arial', 12),command=ToggleToLoginPlayers)
    btne_login.grid(row=1, sticky=W)

def RegisterPlayers():
    Database()
    if USERNAME2.get == "" or PASSWORD2.get() == "" or AGE2.get() == "":
        lbl_result2.config(text="Empty fields!", fg="orange")
    else:
        cursor.execute("SELECT * FROM `players` WHERE `username` = ?", (USERNAME2.get(),))
        if cursor.fetchone() is not None:
            lbl_result2.config(text="Username is already taken", fg="red")
        elif int(AGE2.get())<4:
            lbl_result2.config(text="You are under the age(under 4 years)", fg="red")
        else:
            insert_player(str(USERNAME2.get()), str(PASSWORD2.get()), str(AGE2.get()))
            USERNAME2.set("")
            PASSWORD2.set("")
            AGE2.set("")
            lbl_result2.config(text="Successfully Created!", fg="black")
        cursor.close()
        conn.close()


def ToggleToLoginPlayers(event=None):
    RegisterPlayersFrame.destroy()
    Admin_Form()

def ToggleToRegisterPlayers(event=None):
    AdminFrame.forget()
    RegisterPlayersForm()

def Admin_Form():
    global AdminFrame
    AdminFrame = Frame(windo)
    AdminFrame.pack()

    btn_registerplayers=Button(AdminFrame,text='Register For Players',command=ToggleToRegisterPlayers, width=17, font=('arial', 15),fg='purple')
    btn_registerplayers.grid(row=0, column=2)
    lbl_result_empty = Label(AdminFrame, text="", font=('arial', 18))
    lbl_result_empty.grid(row=1, columnspan=2)

    lbl_result_empty2 = Label(AdminFrame, text="Enter first player", font=('arial', 18))
    lbl_result_empty2.grid(row=2, column=2)

    lbl_player1 = Label(AdminFrame, text="player 1:", font=('arial', 18))
    lbl_player1.grid(row=3, column=1)
    player1 = Entry(AdminFrame, font=('arial', 20), textvariable=PLAYER1, width=15)
    player1.grid(row=3, column=2)
    lbl_password1=Label(AdminFrame, text="password:", font=('arial', 18))
    lbl_password1.grid(row=4, column=1)
    password1=Entry(AdminFrame, font=('arial', 20), textvariable=PASSWOR1, width=15, show="*")
    password1.grid(row=4, column=2)
    lbl_player2 = Label(AdminFrame, text="player 2:", font=('arial', 18))
    player2 = Entry(AdminFrame, font=('arial', 20), textvariable=PLAYER2, width=15)
    lbl_password2 = Label(AdminFrame, text="password:", font=('arial', 18))
    password2 = Entry(AdminFrame, font=('arial', 20), textvariable=PASSWOR2, width=15, show="*")
    lbl_player3 = Label(AdminFrame, text="player 3:", font=('arial', 18))
    player3 = Entry(AdminFrame, font=('arial', 20), textvariable=PLAYER3, width=15)
    lbl_password3 = Label(AdminFrame, text="password:", font=('arial', 18))
    password3 = Entry(AdminFrame, font=('arial', 20), textvariable=PASSWOR3, width=15, show="*")

    lbl_result = Label(AdminFrame, text="", font=('arial', 18))
    lbl_result.grid(row=5, columnspan=2)


    def addthirdplayer():
        Database()
        lbl_result.config(text=" ", fg="red")
        if PLAYER3.get() == "" and PASSWOR3.get() == "":
            tkMessageBox.showinfo('System', 'Please complete the required field!', icon="warning")
        else :
            if  PLAYER1.get() == PLAYER3.get() or PLAYER3.get() == PLAYER2.get():
                tkMessageBox.showinfo('System', 'You Have Enterd This Player before', icon="warning")
            else:
                if PLAYER3.get() == USERNAME.get():
                    lbl_result.config(text="Invalid to add admin", fg="red")
                else:
                    if IsExist(PLAYER3.get(),PASSWOR3.get()):
                        AdminToMenu()
                    else:
                        lbl_result.config(text="Invalid Username or password", fg="red")

    def addsecondetplayer():
        Database()
        lbl_result.config(text=" ", fg="red")
        if PLAYER2.get() == "" and PASSWOR2.get() == "":
            tkMessageBox.showinfo('System', 'Please complete the required field!', icon="warning")
        else:
            if PLAYER1.get() == PLAYER2.get():
                tkMessageBox.showinfo('System', 'You Have Enterd This Player before', icon="warning")
            else:
                if PLAYER2.get() == USERNAME.get():
                    lbl_result.config(text="Invalid to add admin", fg="red")
                else:
                    if IsExist(PLAYER2.get(),PASSWOR2.get()):
                        lbl_player2.forget()
                        player2.forget()
                        lbl_password2.forget()
                        password2.forget()
                        add2_button.forget()
                        lbl_player3.grid(row=3, column=1)
                        player3.grid(row=3, column=2)
                        lbl_password3.grid(row=4, column=1)
                        password3.grid(row=4, column=2)
                        add3_button.grid(row=9, column=2)
                        lbl_result_empty2.config(text="Enter third player")
                    else:
                        lbl_result.config(text="Invalid Username or password", fg="red")


    def addfirstplayer():
        Database()
        lbl_result.config(text=" ", fg="red")
        if PLAYER1.get() == "" and PASSWOR1.get() == "":
            tkMessageBox.showinfo('System', 'Please complete the required field!', icon="warning")
        else:
            if PLAYER1.get()==USERNAME.get():
                lbl_result.config(text="Invalid to add admin", fg="red")
            else:
                if IsExist(PLAYER1.get(),PASSWOR1.get()):
                    lbl_player1.forget()
                    player1.forget()
                    lbl_password1.forget()
                    password1.forget()
                    add1_button.forget()
                    lbl_player2.grid(row=3, column=1)
                    player2.grid(row=3, column=2)
                    lbl_password2.grid(row=4, column=1)
                    password2.grid(row=4, column=2)
                    add2_button.grid(row=9, column=2)
                    lbl_result_empty2.config(text="Enter seconde player")
                else:
                    lbl_result.config(text="Invalid Username or password", fg="red")

    lbl_ = Label(AdminFrame, text="", font=('arial', 18), bd=18)
    lbl_.grid(row=20)

    lbl_remmove = Label(AdminFrame, text="Remove Player:", font=('arial', 18))
    lbl_remmove.grid(row=21, column=1)

    remove_player = Entry(AdminFrame, font=('arial', 20), width=15)
    remove_player.grid(row=21, column=2)


    def Remove_player():
        Database()
        if str(remove_player.get())=='':
            tkMessageBox.showinfo('System', 'Please complete the required field!', icon="warning")
        else:
            if CheckIsAdmin(str(remove_player.get()))==True:
                tkMessageBox.showinfo('System', 'You Cant Remove Admin', icon="warning")
            else:
                cursor.execute("SELECT * FROM players WHERE username =?", (remove_player.get(),))
                if cursor.fetchone() is not None:
                    result = tkMessageBox.askquestion('System', 'Are you sure you want to remove the player', icon="warning")
                    if result == 'yes':
                        deletePlayer(remove_player.get())
                else:
                    tkMessageBox.showinfo('System','this name is not exsists', icon="warning")

    add1_button = Button(AdminFrame, text='Add', width=19,fg='green',command=addfirstplayer)
    add2_button = Button(AdminFrame, text='Add', width=19,fg='green',command=addsecondetplayer)
    add3_button = Button(AdminFrame, text='Add', width=19,fg='green',command=addthirdplayer)
    add1_button.grid(row=9, column=2)


    remove_button = Button(AdminFrame, text='Remove', width=19, command=Remove_player,fg='red')
    remove_button.grid(row=23, column=2)

def checkAge(age):
    if age > 4:
        return True
    return False

def Exit():
    result = tkMessageBox.askquestion('System', 'Are you sure you want to exit?', icon="warning")
    if result == 'yes':
        windo.destroy()
        exit()

def ToggleToLogin():
    RegisterFrame.destroy()
    LoginForm()

def ToggleToRegister():
    LoginFrame.destroy()
    RegisterForm()

def CheckIsAdmin(name):
    cursor.execute("SELECT * FROM `admins` WHERE username=?", (name,))
    if cursor.fetchone() is not None:
        return True
    return False


def RegisterCompanion():
    Database()

    if USERNAME.get() == "" or PASSWORD.get() == "" or AGE.get() == "" or FIRST.get() == "" or LAST.get() == "":
        lbl_resul2.config(text="Empty fields!", fg="purple")
    else:
        cursor.execute("SELECT * FROM `companion` WHERE `username` = ?", (USERNAME.get(),))
        if cursor.fetchone() is not None:
            lbl_resul2.config(text="Username is already taken", fg="red")
        elif int(AGE.get()) < 4:
            lbl_resul2.config(text="You are under the age(under 4 years)", fg="red")
        else:
            insert_companion(USERNAME.get(),PASSWORD.get(),AGE.get() ,FIRST.get() ,LAST.get())
            USERNAME.set("")
            PASSWORD.set("")
            AGE.set("")
            FIRST.set("")
            LAST.set("")
            lbl_resul2.config(text="Successfully Created!", fg="black")
        cursor.close()
        conn.close()

def Register():
    Database()

    if USERNAME.get == "" or PASSWORD.get() == "" or AGE.get() == "":
        lbl_result2.config(text="Empty fields!", fg="purple")
    else:
        cursor.execute("SELECT * FROM `admins` WHERE `username` = ?", (USERNAME.get(),))
        if cursor.fetchone() is not None:
            lbl_result2.config(text="Username is already taken", fg="red")
        elif int(AGE.get()) < 4:
            lbl_result2.config(text="You are under the age(under 4 years)", fg="red")
        else:
            insert_admin(str(USERNAME.get()), str(PASSWORD.get()), str(AGE.get()))
            insert_player(str(USERNAME.get()), str(PASSWORD.get()), str(AGE.get()))
            USERNAME.set("")
            PASSWORD.set("")
            AGE.set("")
            lbl_result2.config(text="Successfully Created!", fg="black")
        cursor.close()
        conn.close()

def Login():
    Database()

    if USERNAME.get == "" or PASSWORD.get() == "":
        lbl_result1.config(text="Empty fields!", fg="purple")
    else:
        cursor.execute("SELECT * FROM `admins` WHERE `username` = ? and `password` = ?", (USERNAME.get(), PASSWORD.get()))
        if cursor.fetchone() is not None:
            lbl_result1.config(text="You Successfully Login", fg="blue")
            LoginToAdmin()
        else:
            lbl_result1.config(text="Invalid Username or password", fg="red")


def LoginCompanion():
    Database()

    if COMPANION_NAME.get == "" or COMPANION_PASSWORD.get() == "":
        lbl_resul1.config(text="Empty fields!", fg="purple")
    else:
        cursor.execute("SELECT * FROM `companion` WHERE `username` = ? and `password` = ?", (COMPANION_NAME.get(), COMPANION_PASSWORD.get()))
        if cursor.fetchone() is not None:
            lbl_resul1.config(text="You Successfully Login", fg="blue")
            ToCompanion()
        else:
            lbl_resul1.config(text="Invalid Username or password", fg="red")

def CompanionForm():
    global CompanionFrame
    CompanionFrame = Frame(windo)
    CompanionFrame.pack()

    global lbl_empt1,lbl_name,lbl_date,lbl_games,lbl_score,lbl_average

    lbl_player1 = Label(CompanionFrame, text="Tracking The Players", font=('arial', 18),fg='blue')
    lbl_player1.grid(row=0,columnspan=2,pady=20)

    lbl_empt1 = Label(CompanionFrame, text="", font=('arial'))
    lbl_empt1.grid(row=1)

    lbl_username = Label(CompanionFrame, text="Enter Player Name :", font=('arial', 18), bd=18)
    lbl_username.grid(row=2)

    lbl_resul1 = Label(CompanionFrame, text="", font=('arial', 18))
    lbl_resul1.grid(row=3, columnspan=2)

    username = Entry(CompanionFrame, font=('arial', 20), textvariable=TRACK_NAME, width=15)
    username.grid(row=2, column=1)

    btne_search = Button(CompanionFrame, text="Search", fg="red", width=35, font=('arial', 18),command=Show_information)
    btne_search.grid(row=3,columnspan=2, pady=20)

    lbl_name = Label(CompanionFrame, text="", font=('arial', 18), bd=18)
    lbl_name.grid(row=4)

    lbl_date = Label(CompanionFrame, text="", font=('arial', 18), bd=18)
    lbl_date.grid(row=5)

    lbl_games = Label(CompanionFrame, text="", font=('arial', 18), bd=18)
    lbl_games.grid(row=6)

    lbl_score = Label(CompanionFrame, text="", font=('arial', 18), bd=18)
    lbl_score.grid(row=7)

    lbl_average = Label(CompanionFrame, text="", font=('arial', 18), bd=18)
    lbl_average.grid(row=8)



def Show_information():
    Database()
    if TRACK_NAME.get() =="":
        lbl_empt1.config(text="Empty field!", fg="red")
        lbl_name.config(text="")
        lbl_date.config(text="")
        lbl_games.config(text="")
        lbl_score.config(text="")
        lbl_average.config(text="")
    else:
        cursor.execute("SELECT * FROM `players` WHERE `username` = ? ", (TRACK_NAME.get(),))
        if cursor.fetchone() is not None:

            cursor.execute("SELECT * FROM players WHERE username=?", (TRACK_NAME.get(),))
            rows = cursor.fetchall()
            score=rows[0][3]
            games=rows[0][4]
            date=rows[0][5]
            if games!=0:
                average=score/games
            else:
                average=0
            lbl_empt1.config(text="")
            lbl_name.config(text="Name:  "+TRACK_NAME.get())
            lbl_date.config(text="Started at: " +date)
            lbl_games.config(text="Total Games: "+str(games))
            lbl_score.config(text="Total Score: " + str(score))
            lbl_average.config(text="Average Score For One Game: " + str(average))

        else:
            lbl_empt1.config(text="Invalid Username", fg="red")
            lbl_name.config(text="")
            lbl_date.config(text="")
            lbl_games.config(text="")
            lbl_score.config(text="")
            lbl_average.config(text="")


def ToCompanion():
    LoginCompanionFrame.destroy()
    CompanionForm()

def LoginToAdmin():
    LoginFrame.destroy()
    Admin_Form()

def ToggleToGame():
    AdminFrame.destroy()
    GameForm()

def GameForm():#screen of the game
    global GameFrame
    GameFrame = Frame(windo)
    GameFrame.pack()
    lbl_player1 = Label(GameFrame, text="GAME SCREEN", font=('arial', 18))
    lbl_player1.pack()

def IsExist(name,password):
    Database()
    cursor.execute("SELECT * FROM `players` WHERE `username` =? and `password` = ?",(name,password,))
    if cursor.fetchone() is not None:
        return  True

    return False


def MenuForm():
    global MenuFrame

    MenuFrame = Frame(windo)
    MenuFrame.pack(side=TOP, pady=80)
    btnStyle = ttk.Style()
    btnStyle.configure('TButton', height=40, width=40, font=('arial', 20))

    exit_btn = ttk.Button(MenuFrame, text='Exit', command=Exit, style='TButton')
    exit_btn.pack()

    play_btn = ttk.Button(MenuFrame, text='Play', command=ToggleToGame, style='TButton')
    play_btn.pack()

    credits_btn = ttk.Button(MenuFrame, text='Credits', style='TButton', command=MenuToCreadit)
    credits_btn.pack()

    sitting_btn = ttk.Button(MenuFrame, text='Sittings', command=ToggleToSitting, style='TButton')
    sitting_btn.pack()

    about_btn = ttk.Button(MenuFrame, text='Help', style='TButton', command=MenuToHelp)
    about_btn.pack()

    buy_btn = ttk.Button(MenuFrame, text='Buy The Game', style='TButton', command=buygmae)
    buy_btn.pack()

    windo.configure(bg=COLORH.get())


def SittingsForm():
    global SittingsFrame

    SittingsFrame = Frame(windo)
    SittingsFrame.pack(side=TOP, pady=80)

    sound_btn = Button(SittingsFrame, text='Sound', font=('arial', 20), command=stop_)
    sound_btn.pack()

    back_btn = Button(SittingsFrame, text='Change Back-Ground', font=('arial', 20), command=ChangeBackGround)
    back_btn.pack()

    ret_btn = Button(SittingsFrame, text='Return To Menu', font=('arial', 20), command=RetMenu)
    ret_btn.pack()


def ToggleToGame(event=None):
    MenuFrame.destroy()
    GameForm()


def ChangeBackGround():
    if COLORH.get() == "light green":
        COLORH.set("purple")
        windo.configure(bg="purple")
    else:
        COLORH.set("light green")
        windo.configure(bg="light green")


def ToggleToSitting():
    MenuFrame.destroy()
    SittingsForm()



def RetMenu():
    SittingsFrame.destroy()
    MenuForm()


def CreaditsForm():
    global CreaditsFrame
    CreaditsFrame = Frame(windo)
    CreaditsFrame.configure(bg='red')
    T = Text(CreaditsFrame, height=15, width=80, font=('arial', 14))
    T.pack()
    quote = """
    מפתחי המשחק :
    -ריזק אבו מדיעים  rezeqab@ac.sce.ac.il 
    -עזאלדין אלקרעאן  alkoran1234@gmail.com 
    -אחמד אבו מדיעים  ahmadab8@ac.sce.ac.il
    -עומר חמדיה  omarhm@ac.sce.ac.il
    """
    T.insert(END, quote)
    T.config(state=DISABLED)
    newbtb = Button(CreaditsFrame, text='Return To Menu', font=('arial', 20), command=CreaditToMenu)
    newbtb.pack()
    CreaditsFrame.pack()


def HelpForm():
    global HelpFrame
    HelpFrame = Frame(windo)
    HelpFrame.configure(bg='red')
    T = Text(HelpFrame, height=15, width=80, font=('arial', 14))
    T.pack()
    quote = """
    מטרות המשחק:
    לעזור לאוכלודסיה מסוימת בעלת צריכים מיוחדים ונשפר המצב שלה
    הוראורת המשחק:
    המשחק מרוכב מ4 שחקנים אחד מהם הוא השחקן המרכזי כל סיבוב השחקן המרכזי מקבל שאלה ושאר השחקנים מקבלים כל רחד 5 כלפי תשובות,כל אחד מהשחקנים בוחר כלף תשובה שהיא עונה על השאלה לפי דעתו , אחר כך השחקן המרכזי בוחר המנצח לסיבוב והמנצח מקבל נקודה,המשחק מסתיים אחר שחקן מקבל 5 נקודות 
    """
    T.insert(END, quote)
    T.config(state=DISABLED)

    newbtb1 = Button(HelpFrame, text='Return To Menu', font=('arial', 20), command=HelpToMenu)
    newbtb1.pack()
    HelpFrame.pack()

def buygmae():
    webbrowser.open("https://adhdshop.co.il/all-products/link/")

def HelpToMenu():
    HelpFrame.destroy()
    MenuForm()


def MenuToHelp():
    MenuFrame.destroy()
    HelpForm()


def CreaditToMenu():
    CreaditsFrame.destroy()
    MenuForm()


def MenuToCreadit():
    MenuFrame.destroy()
    CreaditsForm()

def AdminToMenu():
    AdminFrame.destroy()
    MenuForm()

def ChooseToLogin():
    Choose_AccountFrame.destroy()
    LoginForm()


def ChooseToCompanion():
    Choose_AccountFrame.destroy()
    LoginCompanionForm()


def LoginForm():
    global LoginFrame, lbl_result1

    LoginFrame = Frame(windo)
    LoginFrame.pack()

    lbl_result_empty = Label(LoginFrame, text="Login For Admins", font=('arial', 18),fg="blue")
    lbl_result_empty.grid(row=0, columnspan=2)

    lbl_username = Label(LoginFrame, text="Admin Username:", font=('arial', 18), bd=18)
    lbl_username.grid(row=2)

    lbl_password = Label(LoginFrame, text="Admin Password:", font=('arial', 18), bd=18)
    lbl_password.grid(row=3)

    lbl_result1 = Label(LoginFrame, text="", font=('arial', 18))
    lbl_result1.grid(row=4, columnspan=2)

    username = Entry(LoginFrame, font=('arial', 20), textvariable=USERNAME, width=15)
    username.grid(row=2, column=1)

    password = Entry(LoginFrame, font=('arial', 20), textvariable=PASSWORD, width=15, show="*")
    password.grid(row=3, column=1)

    btn_login = Button(LoginFrame, text="Login", font=('arial', 18), width=35, command=Login,fg='red')
    btn_login.grid(row=5, columnspan=2, pady=20)

    btne_register = Button(LoginFrame, text="Creat Account", fg="red", width=35,font=('arial', 18),command=ToggleToRegister)
    btne_register.grid(row=6, columnspan=2, pady=20)

def RegisterForm():
    global RegisterFrame, lbl_result2

    RegisterFrame = Frame(windo)
    RegisterFrame.pack()

    lbl_result_empty = Label(RegisterFrame, text="Register For Admins", font=('arial', 18),fg="blue")
    lbl_result_empty.grid(row=0, columnspan=2)

    lbl_username = Label(RegisterFrame, text="Admin Username:", font=('arial', 18), bd=18)
    lbl_username.grid(row=2)

    lbl_password = Label(RegisterFrame, text="Admin Password:", font=('arial', 18), bd=18)
    lbl_password.grid(row=3)

    lbl_age = Label(RegisterFrame, text="Admin Age:", font=('arial', 18), bd=18)
    lbl_age.grid(row=4)

    lbl_result2 = Label(RegisterFrame, text="", font=('arial', 18))
    lbl_result2.grid(row=6, columnspan=2)

    username = Entry(RegisterFrame, font=('arial', 20), textvariable=USERNAME, width=15)
    username.grid(row=2, column=1)

    password = Entry(RegisterFrame, font=('arial', 20), textvariable=PASSWORD, width=15, show="*")
    password.grid(row=3, column=1)

    age = Entry(RegisterFrame, font=('arial', 20), textvariable=AGE, width=15)
    age.grid(row=4, column=1)

    btn_login = Button(RegisterFrame, text="Register", font=('arial', 18), width=35, command=Register,fg='red')
    btn_login.grid(row=7, columnspan=2, pady=20)

    btne_login = Button(RegisterFrame, text="Return To Login", fg="red", width=35, font=('arial', 18),command=ToggleToLogin)
    btne_login.grid(row=8,columnspan=2, pady=20)

def ToggleToRegisterCompanion():
    LoginCompanionFrame.destroy()
    RegisterCompanionForm()

def LoginCompanionForm():
    global LoginCompanionFrame, lbl_resul1

    LoginCompanionFrame = Frame(windo)
    LoginCompanionFrame.pack()

    lbl_result_empty = Label(LoginCompanionFrame, text="Login For Companion", font=('arial', 18),fg="blue")
    lbl_result_empty.grid(row=0, columnspan=2)

    lbl_username = Label(LoginCompanionFrame, text="Companion Username:", font=('arial', 18), bd=18)
    lbl_username.grid(row=2)

    lbl_password = Label(LoginCompanionFrame, text="Companion Password:", font=('arial', 18), bd=18)
    lbl_password.grid(row=3)

    lbl_resul1 = Label(LoginCompanionFrame, text="", font=('arial', 18))
    lbl_resul1.grid(row=4, columnspan=2)

    username = Entry(LoginCompanionFrame, font=('arial', 20), textvariable=COMPANION_NAME, width=15)
    username.grid(row=2, column=1)

    password = Entry(LoginCompanionFrame, font=('arial', 20), textvariable=COMPANION_PASSWORD, width=15, show="*")
    password.grid(row=3, column=1)

    btn_login = Button(LoginCompanionFrame, text="Login", font=('arial', 18), width=35, command=LoginCompanion,fg='red')
    btn_login.grid(row=5, columnspan=2, pady=20)

    btne_register = Button(LoginCompanionFrame, text="Creat Account", fg="red", width=35,font=('arial', 18),command=ToggleToRegisterCompanion)
    btne_register.grid(row=6, columnspan=2, pady=20)

def RegisterCompanionForm():
    global RegisterCompanionFrame, lbl_resul2

    RegisterCompanionFrame = Frame(windo)
    RegisterCompanionFrame.pack()

    lbl_result_empty = Label(RegisterCompanionFrame, text="Register For Companion", font=('arial', 18),fg="blue")
    lbl_result_empty.grid(row=0, columnspan=2)

    lbl_username = Label(RegisterCompanionFrame, text="Companion Username:", font=('arial', 18), bd=18)
    lbl_username.grid(row=2)

    lbl_password = Label(RegisterCompanionFrame, text="Companion Password:", font=('arial', 18), bd=18)
    lbl_password.grid(row=3)

    lbl_age = Label(RegisterCompanionFrame, text="Companion Age:", font=('arial', 18), bd=18)
    lbl_age.grid(row=4)

    lbl_first = Label(RegisterCompanionFrame, text="First Name:", font=('arial', 18), bd=18)
    lbl_first.grid(row=5)

    lbl_last = Label(RegisterCompanionFrame, text="Last Name:", font=('arial', 18), bd=18)
    lbl_last.grid(row=6)

    lbl_resul2 = Label(RegisterCompanionFrame, text="", font=('arial', 18))
    lbl_resul2.grid(row=8, columnspan=2)

    username = Entry(RegisterCompanionFrame, font=('arial', 20), textvariable=USERNAME, width=15)
    username.grid(row=2, column=1)

    password = Entry(RegisterCompanionFrame, font=('arial', 20), textvariable=PASSWORD, width=15, show="*")
    password.grid(row=3, column=1)

    age = Entry(RegisterCompanionFrame, font=('arial', 20), textvariable=AGE, width=15)
    age.grid(row=4, column=1)

    last_ = Entry(RegisterCompanionFrame, font=('arial', 20), textvariable=LAST, width=15)
    last_.grid(row=6, column=1)

    first_= Entry(RegisterCompanionFrame, font=('arial', 20), textvariable=FIRST, width=15)
    first_.grid(row=5, column=1)

    btn_login = Button(RegisterCompanionFrame, text="Register", font=('arial', 18), width=35, command=RegisterCompanion,fg='red')
    btn_login.grid(row=9, columnspan=2, pady=20)

    btne_login = Button(RegisterCompanionFrame, text="Return To Login", fg="red", width=35, font=('arial', 18),command=ToggleToLoginCompanion)
    btne_login.grid(row=10,columnspan=2, pady=20)

def ToggleToLoginCompanion():
    RegisterCompanionFrame.destroy()
    LoginCompanionForm()
def questions():
    file = open("questions.txt", "r")
    questionsList=file.readlines()
    file.close()
    return questionsList
def answers():
    list = random.sample(range(0, 142), 15)
    file = open("answers.txt", "r")
    string_word = ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '']
    stre = file.readlines()
    for i in range(15):
        string_word[i] = stre[list[i]]
    file.close()
    return string_word


def GameForm():
    global GameFrame
    question = ''
    questionsList = []
    GameFrame = Frame(windo)
    GameFrame.pack()
    start = datetime.datetime.now()

    def player(name, answer, score):
        return [name, answer, score]

    def times():
        elapsed = datetime.datetime.now() - start

        lbl_time.config(text='Time is : ' + str(elapsed))
        lbl_time.after(1000, times)

    rre = 0

    def chose_question():
        nonlocal question

        questionsList = questions()
        index = random.randint(0, len(questionsList) - 1)
        question = questionsList[index]
        questionsList.remove(question)
        qes.config(text=question)

    def fun(btn):
        nonlocal rre

        if rre > 2:
            rre = 0
            next_round(players)
        helpListPlayers = [list_player1, list_player2, list_player3]
        convert_answers(helpListPlayers[rre])
        for i in playerList:
            i.config(fg='red')
        playerList[rre].config(fg='black')
        rre += 1

    def funcc(btn):
        save_Player_answer(btn)
        fun(btn)
        show_score()

    def save_Player_answer(btn):  # بحفظ جواب كل لاعب
        playerName = playerList[rre - 1]['text'][6:-4]
        for p in players:
            if p[0] == playerName:
                p[1] = btn['text']

    def next_round(list):
        nonlocal mainPlayer

        newlist = []
        for p in list:
            if p[1] != '':
                newlist.append(p)
        Game_to_winner_round(newlist)
        for p in list:  # clear answers
            p[1] = ''
        distribution()
        chose_question()
        playerList.append(mainPlayer)
        mainPlayer.config(fg='red')
        mainPlayer = playerList[0]
        playerList.remove(mainPlayer)
        mainPlayer.config(fg='blue')

    list_player1 = [' ', ' ', ' ', ' ', ' ']
    list_player2 = [' ', ' ', ' ', ' ', ' ']
    list_player3 = [' ', ' ', ' ', ' ', ' ']
    list = answers()

    def distribution():  # توزيع بطاقات
        list = answers()
        for i in range(5):
            list_player1[i] = list[i]

        c = 0
        for i in range(5, 10):
            list_player2[c] = list[i]
            c += 1

        c = 0
        for i in range(10, 15):
            list_player3[c] = list[i]
            c = c + 1

    def convert_answers(list_):
        btn1.config(text=list_[0])
        btn2.config(text=list_[1])
        btn3.config(text=list_[2])
        btn4.config(text=list_[3])
        btn5.config(text=list_[4])

    menubar = Menu(GameFrame)
    filemenu = Menu(menubar, tearoff=0)
    filemenu.add_command(label="Exit", command=Exit)
    menubar.add_cascade(label="File", menu=filemenu)
    windo.config(menu=menubar)
    global lbl_, lbl_1, lbl_2, lbl_3, players
    lbl_time = Label(GameFrame, fg='red', font=('arial', 18))
    lbl_time.pack(side='top', pady=5, anchor='sw')
    players = [player(USERNAME.get(), '', 0), player(PLAYER1.get(), '', 0), player(PLAYER2.get(), '', 0),
               player(PLAYER3.get(), '', 0)]  # list of players names and score and answer
    lbl_ = Label(GameFrame, text='Score ' + USERNAME.get() + ' : {}'.format(players[0][2]), fg='red',
                 font=('arial', 18))
    lbl_.pack(side='top', pady=5, anchor='sw')

    lbl_1 = Label(GameFrame, text='Score ' + PLAYER1.get() + ' : {}'.format(players[1][2]), fg='red',
                  font=('arial', 18))
    lbl_1.pack(side='top', pady=5, anchor='sw')

    lbl_2 = Label(GameFrame, text='Score ' + PLAYER2.get() + ' : {}'.format(players[2][2]), fg='red',
                  font=('arial', 18))
    lbl_2.pack(side='top', pady=5, anchor='sw')

    lbl_3 = Label(GameFrame, text='Score ' + PLAYER3.get() + ' : {}'.format(players[3][2]), fg='red',
                  font=('arial', 18))
    lbl_3.pack(side='top', pady=5, anchor='sw')

    AddGame(USERNAME.get())
    AddGame(PLAYER1.get())
    AddGame(PLAYER2.get())
    AddGame(PLAYER3.get())

    qes = Button(GameFrame, text="aa")
    qes.pack(side='top', padx=10, pady=5, anchor='s')
    qes.config(image=Question, compound='center', fg='red', font=('arial', 18))
    btn1 = Button(GameFrame, text="Click", command=lambda: funcc(btn1))
    btn1.pack(side='left', padx=10, pady=5, anchor='sw')
    btn1.config(image=buttonImag, compound='center', fg='#ffffff', font=('arial', 18))

    btn2 = Button(GameFrame, text="Quit", command=lambda: funcc(btn2))
    btn2.pack(side='left', pady=5, anchor='sw')
    btn2.config(image=buttonImag, compound='center', fg='#ffffff', font=('arial', 18))

    btn3 = Button(GameFrame, text="Click", command=lambda: funcc(btn3))
    btn3.pack(side='left', padx=10, pady=5, anchor='sw')
    btn3.config(image=buttonImag, compound='center', fg='#ffffff', font=('arial', 18))

    btn4 = Button(GameFrame, text="Quit", command=lambda: funcc(btn4))
    btn4.pack(side='left', pady=5, anchor='sw')
    btn4.config(image=buttonImag, compound='center', fg='#ffffff', font=('arial', 18))

    btn5 = Button(GameFrame, text="Quit", command=lambda: funcc(btn5))
    btn5.pack(side='left', padx=10, pady=5, anchor='sw')
    btn5.config(image=buttonImag, compound='center', fg='#ffffff', font=('arial', 18))
    show_score()
    mainPlayer = lbl_
    mainPlayer.config(fg='blue')
    playerList = [lbl_1, lbl_2, lbl_3]
    distribution()
    chose_question()
    fun(btn1['text'])
    times()


def show_score():
    lbl_.config(text='Score ' + USERNAME.get() + ' : {}'.format(players[0][2]))
    lbl_1.config(text='Score ' + PLAYER1.get() + ' : {}'.format(players[1][2]))
    lbl_2.config(text='Score ' + PLAYER2.get() + ' : {}'.format(players[2][2]))
    lbl_3.config(text='Score ' + PLAYER3.get() + ' : {}'.format(players[3][2]))

def choose_winner_round(list):

    global RoundFrame
    RoundFrame = Frame(windo)
    RoundFrame.pack()
    lbl_3_ = Label(RoundFrame, text='Choose the winner ', fg='red', font=('arial', 18))
    lbl_3_.pack(side='top', pady=5, anchor='sw')
    btn1_ = Button(RoundFrame, text=list[0][1],command=lambda :Show_Winner(list[0]))
    btn1_.pack(side='left', padx=10, pady=5, anchor='sw')
    btn1_.config(image=buttonImag, compound='center', fg='#ffffff', font=('arial', 18))
    btn2_ = Button(RoundFrame, text=list[1][1], command=lambda :Show_Winner(list[1]))
    btn2_.pack(side='left', pady=5, anchor='sw')
    btn2_.config(image=buttonImag, compound='center', fg='#ffffff', font=('arial', 18))
    btn3_ = Button(RoundFrame, text=list[2][1],command=lambda :Show_Winner(list[2]))
    btn3_.pack(side='left', padx=10, pady=5, anchor='sw')
    btn3_.config(image=buttonImag, compound='center', fg='#ffffff', font=('arial', 18))

    def Show_Winner(Winner_rond):
        RoundFrame.forget()
        global ShowFrame
        ShowFrame = Frame(windo)
        ShowFrame.pack()
        Winner_rond[2] += 1
        lbl_result112 = Label(ShowFrame, text='The Winner is : ' + Winner_rond[0], font=('arial', 50), bd=18)
        lbl_result112.pack()
        WINNER.set(Winner_rond[0])
        AddScore(Winner_rond[0])
        btnn2_ = Button(ShowFrame, text='Press Here To Continue', command=Winner_round_to_gamer)
        btnn2_.pack(side='left', pady=5, anchor='sw')
        btnn2_.config(compound='center', fg='purple', font=('arial', 18))
        if Winner_rond[2]>=5:
            ShowToChoises()


def Game_to_winner_round(list):
    GameFrame.forget()
    choose_winner_round(list)

def Winner_round_to_gamer(event=None):
    ShowFrame.destroy()
    GameFrame.pack()
    show_score()


def ChoisesToMenu(event=None):
    ChoesisFrame.destroy()
    MenuForm()


def ShowToChoises(event=None):
    ShowFrame.destroy()
    ChoesisForm()


def ChoesisForm():
    global ChoesisFrame
    ChoesisFrame = Frame(windo)
    ChoesisFrame.pack()
    _result112 = Label(ChoesisFrame, text='The Winner Is '+WINNER.get(), font=('arial', 50), bd=18,fg='blue')
    _result112.pack()

    bl_result112 = Label(ChoesisFrame, text='Choose one from this options', font=('arial',25), bd=18)
    bl_result112.pack()

    tnn2_ = Button(ChoesisFrame, text='Exit', command=Exit)
    tnn2_.pack(side='left', pady=5, anchor='sw')
    tnn2_.config(compound='center', fg='purple', font=('arial', 18))

    tnn3_ = Button(ChoesisFrame, text='Return to menu', command=ChoisesToMenu)
    tnn3_.pack(side='left', pady=5, anchor='sw')
    tnn3_.config(compound='center', fg='purple', font=('arial', 18))

Choose_Account_Form()

windo.mainloop()