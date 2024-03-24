if (response.data["username_error"]) { //If server response says username is not unique
  //Failure alert on modal
  this.$set(this.newUsernameAlert, "message",
    "Username already in use, please select another. Entries are converted to lower case.")
  this.$set(this.newUsernameAlert, "variant", "warning")
  this.$set(this.newUsernameAlert, "show", true)
  console.log("non-unique username error");
  return
}
//If successful:
//Show success alert on modal
this.$set(this.newUsernameAlert, "message", "Username updated successfully")
this.$set(this.newUsernameAlert, "variant", "success")
this.$set(this.newUsernameAlert, "show", true)