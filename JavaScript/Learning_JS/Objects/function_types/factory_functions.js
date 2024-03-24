//Similar to constructor functions, but rather than using the "new" keyword, an object is created and returned

function createRobot(name) {
    return {
        name: name,
        talk: function () {
            console.log('My name is ' + name + ', the robot.');
        }
    };
}

//Create a robot with name Chitti
const robo1 = createRobot('Chitti');

robo1.talk();