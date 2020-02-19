const input = document.getElementById('inputBox');
const button = document.getElementById('button');

let astronauts = new Module.AstronautRepository();
let planets = new Module.PlanetRepository();
let mission = new Module.Mission();
//    Engine eng(cin, cout, astronauts, planets, mission);
//    eng.run();
let engine = new Module.JSTestEngine(astronauts, planets, mission);

button.addEventListener('click', () => {
    let output = engine.action(input.value);
    //if (output == "Край" || output == "End");
    console.log(output);
    input.value = '';
});
