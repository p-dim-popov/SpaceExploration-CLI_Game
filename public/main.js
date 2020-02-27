const input = document.getElementById('string');
const button = document.querySelector('input[type="button"]');
const outputBox = document.getElementById('output');

const audio = document.getElementById('music');
audio.muted = true;
setTimeout(() => audio.play(), 5000);

let astronauts = new Module.AstronautRepository();

let planets = new Module.PlanetRepository();
let mission = new Module.Mission();
let engine = new Module.JSTestEngine(astronauts, planets, mission);

button.addEventListener('click', enterInputHandler);
input.addEventListener('keypress', (e) => {
    if (e.key === 'Enter') {
        e.preventDefault();
        enterInputHandler();
    }
});

function enterInputHandler() {
    let output;
    try {
        output = engine.action(input.value);
        outputBox.textContent += output + '\n';
        input.value = '';
    }
    catch (e) {
        outputBox.textContent += "Грешни аргументи или непълна команда" + '\n' //no exception handling from emscripten
    }
    finally {
        outputBox.scrollTop = outputBox.scrollHeight;
    }
}
