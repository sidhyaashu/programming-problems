const { Animal } = require("./First_class");

class Cat extends Animal {
    #weight
    constructor(name,age,weight){
        super(name,age)
        this.#weight = weight
    }

    setWeight(weight){
        this.#weight = weight //setter
    }

    getWeight(){
        return this.#weight //getter
    }
}

module.exports = {
    Cat
}