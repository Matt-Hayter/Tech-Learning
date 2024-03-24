#  @Bek Brace [ Twitter - Dev.to - GitHub ]
#  VueJs - Flask Full-Stack Web Application
#  bekbrace.com - info@bekbrace.com
#  Source Code : Michael Hermann [ mjheaO ]

from flask import Flask, jsonify, request 
from flask_cors import CORS
#For generating random, unique ids for each game
import uuid

app = Flask(__name__)

app.config.from_object(__name__)

#Enable CORS to allow complete separation of Vue and Flask
CORS(app, resources = {r"/*": {"origins": "*"}}) #Any origin
#CORS(app, resources={r'/*':{'origins': 'http://localhost:8080',"allow_headers": "Access-Control-Allow-Origin"}}) #Specific origin that's Vue's default server

#THESE ROUTES ARE NOT REALLY PART OF THE APP, but can be accessed in browser according to the relative route
@app.route('/', methods=['GET'])
def greetings():
    return("Hello, world!")

@app.route('/shark', methods=['GET'])
def shark():
    return("Shark🦈!")

#Could use a database here: MySQL or mongoDB. Instead, hard coding for simplicity
GAMES = [

    {   'id': uuid.uuid4().hex,
        'title':'2k21',
        'genre':'sports',
        'played': True,
    },
    {   'id': uuid.uuid4().hex,
        'title':'Evil Within',
        'genre':'horror',
        'played': False,
    },
    {   'id': uuid.uuid4().hex,
        'title':'the last of us',
        'genre':'survival',
        'played': True,
    },
    {  'id': uuid.uuid4().hex,
        'title':'days gone',
        'genre':'horror/survival',
        'played': False,
    },
    {   'id': uuid.uuid4().hex,
        'title':'mario',
        'genre':'retro',
        'played': True,
    }

]

# The GET and POST route handler
# Default http method is get, so if "POST" is needed, need to import request library
@app.route('/games', methods=['GET', 'POST'])
def all_games():
    #Default response when http request is successful
    response_object = {'status':'success'}
    #Post called when a child resource is being added
    if request.method == "POST":
        #Client posting data, which will be recieved in the json format
        post_data = request.get_json()
        #Add user inputted data to saved data, would usually tend to be a database, but in this case in a GAMES array
        GAMES.append({
            #Need a unique ID for each game
            'id' : uuid.uuid4().hex,
            #Get data from post request
            'title': post_data.get('title'),
            'genre': post_data.get('genre'),
            'played': post_data.get('played')})
        #Thought we would expect an index error here (without defaultdict) as "message" is not a current key?
        response_object['message'] =  'Game Added!'
    #In the case of a get request, just display all games
    else:
        response_object['games'] = GAMES
    #Need to convert response to json before returning (client data is in json format)
    return jsonify(response_object)


#The PUT and DELETE route handler
#<game_id> passes the value at relative position of HTTP request (/games/...) as arg to following functions
#The game's id will be a unique identifier  (generated using uuid)
@app.route('/games/<game_id>', methods =['PUT', 'DELETE'])
def single_game(game_id):
    response_object = {'status':'success'}
    #For updating game. Put called when a single resource is being modified -> PUT overwrights resource, POST adds a new resource
    if request.method == "PUT":
        #Data recieved from client
        post_data = request.get_json()
        #Game needs to be removed first if it's going to be updated
        remove_game(game_id)
        GAMES.append({
            #Generates a random id as a hexedecimal number
            'id' : uuid.uuid4().hex,
            'title': post_data.get('title'),
            'genre': post_data.get('genre'),
            'played': post_data.get('played')
        })
        response_object['message'] =  'Game Updated!'
    #For removing game
    if request.method == "DELETE":
        remove_game(game_id)
        response_object['message'] = 'Game removed!'    
    return jsonify(response_object)


# Removing the game to update / delete
#Called within single_game route
def remove_game(game_id):
    for game in GAMES:
        #Only remove game if id matches the target id
        if game['id'] == game_id:
            GAMES.remove(game)
            return True
    return False

if __name__ == "__main__":
    app.run(debug=True)

