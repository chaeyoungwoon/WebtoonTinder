let currentWebtoonIndex = 0;
let webtoons = [];

function fetchWebtoons() {
    fetch('/webtoons')
        .then(response => response.json())
        .then(data => {
            webtoons = data;
            displayWebtoon();
        });
}

function displayWebtoon() {
    const container = document.getElementById('webtoon-container');
    if (currentWebtoonIndex < webtoons.length) {
        const webtoon = webtoons[currentWebtoonIndex];
        container.innerHTML = `<h2>${webtoon.title}</h2><p>${webtoon.genre}</p><p>${webtoon.description}</p>`;
    } else {
        container.innerHTML = `<p>No more webtoons.</p>`;
    }
}

function swipe(action) {
    const webtoon = webtoons[currentWebtoonIndex];
    fetch('/swipe', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ webtoon_id: webtoon.id, action: action })
    })
    .then(response => response.json())
    .then(data => {
        console.log(data);
        currentWebtoonIndex++;
        displayWebtoon();
    });
}

window.onload = fetchWebtoons;
