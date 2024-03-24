<!--Main Games component for web app-->

<!--Template used for Vue html scope-->
<template>
<div class="jumbotron vertical-center">
  <div class="container">
    <!-- Use Bootswatch CDN, for CSS styling theme in bootstrap (CSS framework). The following html line is all copied from Bootswatch website-->
   <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootswatch@4.5.2/dist/sketchy/bootstrap.min.css" integrity="sha384-RxqHG2ilm4r6aFRpGmBbGTjsqwfqHOKy1ArsMhHusnRO47jcGqpIQqlQK/kmGy9R" crossorigin="anonymous">
    <!-- <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootswatch@4.5.2/dist/superhero/bootstrap.min.css" integrity="sha384-HnTY+mLT0stQlOwD3wcAzSVAZbrBp141qwfR4WfTqVQKSgmcgzk+oP0ieIyrxiFO" crossorigin="anonymous"> -->

    <div class="row">
      <!--CSS Bootstrap classes: these are included using class names seperated by spaces (see bootstrap class examples) -->
      <!--Creates automatic styling without the need for manually writing the CSS, allowed due to linked stylesheet-->
      <div class="col-sm-12 ">
       <h1 class="text-center bg-primary text-white" style="border-radius:10px"> Games Library 🕹️ </h1>
        <!--Horizintal line and breaking line-->
        <hr><br>
        
         <!-- Alert -->
         <!-- Bootstrap Vue alert (b-alert)-->
         <!--v-... directive (directives tell vue to do something)-->
        <b-alert variant="success" v-if="showMessage" show> {{ message }} </b-alert>
        <!-- Add Game button -->
        <!-- Mount modal with id = game-modal to button-->
        <button type="button" class="btn btn-success btn-sm" v-b-modal.game-modal >Add Game</button>
        <br><br>
        <!-- Add a bootstrap table -->
        <table class="table table-hover">
          <!--Table head-->
          <thead>
            <tr>
              <!-- table header cells -->
              <!-- Scope used to specify whether header cell is a header for column, row etc. No visual effect in ordinary web browsers-->
              <th scope="col">Title</th>
              <th scope="col">Genre</th>
              <th scope="col">Played ?</th>
              <th scope="col">Actions</th>
            </tr>
          </thead>
          <tbody>
            <!-- tr: table row -->
            <!--v-... directive, for loops in view use v-for: -->
            <!--Games is a member of Vue component data-->
            <tr v-for="(game, index) in games" :key="index">
              <!-- td : table data -->
              <td>{{game.title}}</td>
              <td>{{game.genre}}</td>
              <td>
                <!--Again with Vue directives, this time if, else-->
                <span v-if="game.played">Yes</span>
                <span v-else>No</span>
              </td>
              <td>
                <div class="btn-group" role="group">
                <!-- 2 Handle update button click -->
                <!-- Attaching game-update-modal for whe editting game-->
                <!-- Upon botton click, editGame(game) method is first run so that Vue data corresponds to correct game. The modal is then loaded, and corresponding @submit or @reset methods upon further clicks on the b-button modal component-->
                <button
                  type="button"
                  class="btn btn-info btn-sm"
                  v-b-modal.game-update-modal
                  @click="editGame(game)"> Update </button>
                <button 
                  type="button"
                  class="btn btn-danger btn-sm"
                  @click="deleteGame(game)"> Delete </button>
                </div>
              </td>
            </tr>
          </tbody>
        </table>
        
        <!-- Footer -->
        <Footer class="bg-primary text-white text-center" style="border-radius:10px">Copyright &copy;. All Rights Reserved 2021.</Footer>

      </div>
    </div>


    <!--Now for modals, one for edit and one for submit, which use Vue bootstrap for forms and inputs:-->

    <!-- Start of Modal 1: -->
    <!-- *This is using bootstrap Vue modal (b-modal)*. A modal is a flexible dialog prompt -->

    <!--hide-backdrop etc. are bootstap methods?-->
    <!-- "ref" attribute allows for a direct reference to a specific DOM element after it is mounted (in this case, Modal 1)-->
    <b-modal ref="addGameModal"
         id="game-modal"
         title="Add a new game" hide-backdrop
         hide-footer
         >
      <!--Bootstrap Vue form, using custom validation (@method). Class is using bootstrap customisations again, as stylesheet is still linked-->
      <!--Form that appears within modal-->
      <!--The submit b-button method fires the onSubmit function, and reset method fires the onReset function -->
      <b-form @submit="onSubmit" @reset="onReset" class="w-100">

        <!--Contents of a group can be seen as a collective item on form-->
        <b-form-group id="form-title-group"
                      label="Title:"
                      label-for="form-title-input">
          <!-- *v-model is a Vue directive that binds input values back to javascript (then also accessed accessed in backend with post_data.get('title')?)*-->
          <b-form-input id="form-title-input"
                        type="text"
                        v-model="addGameForm.title"
                        required
                        placeholder="Enter title">
          </b-form-input>
        </b-form-group>

        <!-- *Notice v-model directive again* -->
        <b-form-group id="form-genre-group"
                      label="Genre:"
                      label-for="form-genre-input">
              <b-form-input id="form-genre-input"
                            type="text"
                            v-model="addGameForm.genre"
                            required
                            placeholder="Enter genre">
            </b-form-input>
          </b-form-group>
        
        <b-form-group id="form-played-group">
          <!-- v-modal directive again-->
          <b-form-checkbox-group v-model="addGameForm.played" id="form-checks">
            <b-form-checkbox value="true">Played?</b-form-checkbox>
          </b-form-checkbox-group>
        </b-form-group>

        <!-- -->
        <!-- Can customise CSS bootstrap variant -->
        <!-- Bootstrap Vue button-->
        <b-button type="submit" variant="outline-info">Submit</b-button>
        <b-button type="reset" variant="outline-danger">Reset</b-button>
      </b-form>
    </b-modal>
  <!-- End of modal 1 -->


  <!-- Start of Modal 2 -->
  <b-modal ref="editGameModal"
         id="game-update-modal"
         title="Update" hide-backdrop
         hide-footer>
  <b-form @submit="onSubmitUpdate" @reset="onResetUpdate" class="w-100">
    
  <b-form-group id="form-title-edit-group"
                label="Title:"
                label-for="form-title-edit-input">
      <b-form-input id="form-title-edit-input"
                    type="text"
                    v-model="editForm.title"
                    required
                    placeholder="Enter title">
      </b-form-input>
    </b-form-group>

    <b-form-group id="form-genre-edit-group"
                  label="Genre:"
                  label-for="form-genre-edit-input">
        <b-form-input id="form-genre-edit-input"
                      type="text"
                      v-model="editForm.genre"
                      required
                      placeholder="Enter genre">
        </b-form-input>
      </b-form-group>
      
    <b-form-group id="form-played-edit-group">
      <b-form-checkbox-group v-model="editForm.played" id="form-checks">
        <b-form-checkbox value="true">Played?</b-form-checkbox>
      </b-form-checkbox-group>
    </b-form-group>

    <b-button-group>
      <b-button type="submit" variant="outline-info">Update</b-button>
      <b-button type="reset" variant="outline-danger">Cancel</b-button>
    </b-button-group>
  </b-form>
</b-modal>
<!-- end of modal 2 -->
  </div>
  </div>
</template>



<script>
//For communication with backend
import axios from 'axios';

//Exporting component object as default module
export default {
  //Format for the data of a Vue component object
  data() { //Equivalent to a pre-ES6 method, data: function(){
    return {
      //Games initialised empty here, but then updated from backend with getGames method, called in created()
      games: [],
      //Updated via v-model directives in html code
      addGameForm: {
        title: '',
        genre: '',
        //Empty list for played as it can be yes or no
        played: [],
      },
      editForm: {
      id: '',
      title: '',
      genre: '',
      played: [],
      },
    };
  },

  message:'',

  methods: {
    // 1 GET METHOD
    getGames() {
      const path = 'http://localhost:5000/games';
      //return promise, response from backend
      axios.get(path)
        .then((res) => {
          this.games = res.data.games;
        })
        .catch((error) => {
          console.error(error);
        });
    },

    // 2 Add Game Button
    //payload is whatever has been passed to this function (in this case a vue-form with the @submit = onsubmit decorator)
    addGame(payload) {
      const path = 'http://localhost:5000/games';
      //Send payload to backend
      axios.post(path, payload)
        .then(() => {
          //Then get all games from backend again
          this.getGames();
          
          // for message alert
          this.message = 'Game added 🕹️ !';
          
          // to show message when game is added
          this.showMessage = true;
  
        })
        .catch((error) => {
          console.log(error);
          this.getGames();
        });
    },

     // 5 initForm - add ediForm after the update method
     initForm() {
        //*These are default values required when a form is created, and are updated using the v-modal directive in html*
        this.addGameForm.title = '';
        this.addGameForm.genre = '';
        this.addGameForm.played = [];
        this.editForm.id = '';
        this.editForm.title = '';
        this.editForm.genre = '';
        this.editForm.played = [];
      }, 

    // 3 Submit form validator in the template @submit="onSubmit"  
    //Fired when form is submitted successfully
    onSubmit(e) {
      //prevent default browser behaviour when submitting?
      e.preventDefault();
      //Hide modal after submission. $refs is used to reference DOM elements thaat have prev. used the ref = ... attribute
      this.$refs.addGameModal.hide();
      let played = false;
      if (this.addGameForm.played[0]) played = true;
      //Create payload for addGame method.
      const payload = {
        title: this.addGameForm.title,
        genre: this.addGameForm.genre,
        played, 
      };
      //Now pass payload to addgame method
      this.addGame(payload);
      //Reset form back to init now game has been added
      this.initForm();
    },

    
  // MODAL 2
  // a- Handle the form Submit after updating
    onSubmitUpdate(e) {
    e.preventDefault();
    this.$refs.editGameModal.hide();
    let played = false;
    if (this.editForm.played[0]) played = true;
    //Create payload for backend, which is copied from recently updated Vue data
    const payload = {
      title: this.editForm.title,
      genre: this.editForm.genre,
      played,
    };
    //Pass form id to be updated, unlike above where this.addGame is just passed the payload (new id is generated in backend)
    this.updateGame(payload, this.editForm.id);
  },

  // b- On reset method to reset items to default values
    onReset(e) {
      e.preventDefault();
      this.$refs.addGameModal.hide();
      this.initForm();
    },

// 4 Update Alert Message 
// Once the update is effective, we will get a message telling us that Game Updated, and display the list of games after the update
updateGame(payload, gameID) {
  //Set path to the id of game
  const path = `http://localhost:5000/games/${gameID}`;
  //Put method, to update existing item
  axios.put(path, payload)    
    .then(() => {
      this.getGames();
      this.message = 'Game updated ⚙️!';
      this.showMessage =  true;
    })
    .catch((error) => {
      console.error(error);
      this.getGames();
    });
},

 // Handle Update Button 
editGame(game) {
  this.editForm = game;
},

// 5 Handle reset / cancel button click
onResetUpdate(e) {
  e.preventDefault();
  this.$refs.editGameModal.hide();
  this.initForm();
  this.getGames(); 
},

// Remove Game [ Delete Button ]
removeGame(gameID) {
  const path = `http://localhost:5000/games/${gameID}`;
  axios.delete(path)
    .then(() => {
      this.getGames();
      this.message = 'Game Removed 🗑️!';
      this.showMessage = true;
    })
    .catch((error) => {
      // eslint-disable-next-line
      console.error(error);
      this.getGames();
    });
},
// Handle Delete Button
deleteGame(game) {
  this.removeGame(game.id);
},

  }, //End of methods


  //Lifecycle hooks: pre-defined methods that get executed in a certain order in the program's lifetime, starting from the initialization of the Vue instance to its destruction
  //created() lifecycle hook calls the getGames method
  //This getGames() component method then fetches the games from the backend
  created() {
    this.getGames(); 
  },
};
</script>