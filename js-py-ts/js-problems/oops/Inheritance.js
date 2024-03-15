const { Animal } = require("./First_class")

class Dog extends Animal{
    constructor(name,age,breed){
        super(name,age)
        this.breed = breed
    }


    bark(){
        return `Woo Hooo`
    }

    showInfo(){
        return `name - ${this.name} and age ${this.age} and breed ${this.breed}`
    }
}


module.exports = {
    Dog
} // Go to index.js page to show the result