class Animal {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  makeSound() {
    return `Makes sound`;
  }
}

class Dog extends Animal {
  constructor(name, age, breed) {
    super(name, age);
    this.breed = breed;
  }

  makeSound() {
    return `Bhao Bhao`;
  }

  showInfo() {
    return `Tne name of the dog is ${this.name} the age of the dog is ${this.age} and the breed of the dog is ${this.breed}`;
  }
}

class Cat extends Animal {
  #weight;
  constructor(name, age, weight) {
    super(name, age);
    this.#weight = weight;
  }

  makeSound() {
    return `Meow Meow`;
  }

  setWeight(weight) {
    this.#weight = weight;
  }

  getWeight() {
    return `The weight of the cat is ${this.#weight}`;
  }
}

const myDog = new Dog("Sidhya", 3, "Zebrandi");
const myCat = new Cat("Sidhya", 3, "5kg");

console.log(myDog.makeSound());
console.log(myCat.makeSound());
