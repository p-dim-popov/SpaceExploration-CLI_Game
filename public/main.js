const input = document.getElementById('string');
const button = document.querySelector('input[type="button"]');
const outputBox = document.getElementById('output');

const audio = document.getElementById('music');
audio.play();

input.addEventListener('keypress', (e) => {
        if (e.key === 'Enter') {
            e.preventDefault();
            enterInputHandler();
        }
    });

let astronauts = new Module.AstronautRepository();
let planets = new Module.PlanetRepository();
let mission = new Module.Mission();
let engine = new Module.JSTestEngine(astronauts, planets, mission);

button.addEventListener('click', enterInputHandler);

function enterInputHandler() {
    let output = engine.action(input.value);
    //if (output == "Край" || output == "End");
    console.log(output);
    outputBox.textContent += output + '\n';
    outputBox.scrollTop = outputBox.scrollHeight;
    input.value = '';
}