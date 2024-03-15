class Animal {
  constructor(name,age) {
    this.name = name;
    this.age = age;
  }

  getInfo() {
    return `The name of the animal is ${this.name} and the age of the animal is ${this.age}`;
  }
}

module.exports = {
    Animal
}