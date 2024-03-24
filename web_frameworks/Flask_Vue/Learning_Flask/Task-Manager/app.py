#app.py is a python package we've created
#Any user interaction on html template (page) calls a route in this script, which processes the request, makes appropriate changes to database and loads up next html template (url path)
from flask import Flask
from flask import render_template #For Jinja templates
from flask import url_for #For linking with css or js using flask
from flask_sqlalchemy import SQLAlchemy #For SQL database implemented with Flask
from flask import request #For request.method (in the case of checking method when there is more than just GET)
from flask import redirect #For directing back to a certain webpage relative to index page
from datetime import datetime #For use in database

#If the source file is executed as the main program, the interpreter sets the __name__ variable to have a value “__main__”. If this file is being imported from another module, __name__ will be set to the module’s name.
app = Flask(__name__) #Pass module's string name to flask
#Informing app as to where database is located
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///test.db' #4 x / = absolute path, 3 x / = relative path. Storing database in test.db file
with app.app_context(): #Needed to fix application context bug for creating database
    db = SQLAlchemy(app) #Initialise database for app

class Todo(db.Model): #Todo inherits database model methods and data
    id = db.Column(db.Integer, primary_key=True) #This is the primary Key, which are all unique
    content = db.Column(db.String(200), nullable = False) #Text column, holding each task (200 character limit). Nullable = False
    date_created = db.Column(db.DateTime, default = datetime.utcnow) #Automatically set date to current time

    def __repr__(self): #__repr__ returns a printable string representation of the object
        return '<Task %r>' % self.id #rather than getting location of object in memory, querying database returns useful string representation


#Need to set up an index route, for url. Use @app.route decorator
@app.route('/', methods=['POST', 'GET']) #Default (without method) is just get
#Index page = URL that loads as a websites "home" page
def index(): #Function is processed every time there is a request
    if request.method == "POST":
        task_content = request.form["content"] #Content of form in html
        new_task = Todo(content=task_content)
        try:
            db.session.add(new_task) #Add new to do list object to database
            db.session.commit() #Commit change to database
            return redirect("/") #Redirect back to index. 
        except:
            return "Problem adding task"
    else: #The case of "GET" (just want to see page and not make changes)
        tasks = Todo.query.order_by(Todo.date_created).all() #Order all Todo objects' data by date created
        return render_template("index.html", tasks=tasks) #Knows to search in templates folder for file name. Passing tasks db variable to flask, to be used in html

#Set up new route for delete
#<int:id> passes the value at relative position of HTTP request as arg to delete() function
@app.route('/delete/<int:id>') #Need to use unique identifier (ie. id) for delete/update
def delete(id):
    task_to_delete = Todo.query.get_or_404(id) #Will try to get, or otherwise 404. Shallow copy
    try:
        db.session.delete(task_to_delete)
        db.session.commit()
        return redirect("/") #GET request
    except:
        return "Problem deleting task"

@app.route("/update/<int:id>", methods=["GET", "POST"])
def update(id):
    task = Todo.query.get_or_404(id) #Shallow copy
    if request.method == "POST": #If post request is made (form is submitted and db change is requested)
        task.content = request.form['content'] #update db
        try:
            db.session.commit()
            return redirect("/") #GET request 
        except:
            return "Issue updating task"
    else:
        return render_template("update.html", task=task)


#If the source file is executed as the main program, the interpreter sets the __name__ variable to have a value “__main__”. If this file is being imported from another module, __name__ will be set to the module’s name.
if __name__ == "__main__": #Checks app.py is the main program's source file, and not being imported to bbe sued elsewhere as a module.
    app.run(debug = True) #If true, run app

'''
Other notes:

<!--Boilerplate html can be created within .html file with !: means it's a section of code repeated in multiple places with little variation-->

'''