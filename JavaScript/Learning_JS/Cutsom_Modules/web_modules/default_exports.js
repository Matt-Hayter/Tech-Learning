//Default export
/*
- .js custom modules can be run using html or Vue
- Used for exporting one main value per module (file)
- Name independent when importing (doesn't have to match)
- Can export other named exports within module with a default
*/
export default class Fruit
{
    constructor(type) {
        this.type = type
    }
    getType() {
        console.log(this.type)
        return this.type
    }
}