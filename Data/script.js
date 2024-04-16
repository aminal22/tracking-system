// JavaScript pour mettre à jour la carte avec la localisation GPS

var map = L.map('map').setView([0, 0], 12); // Initialiser la carte avec une vue par défaut

// Ajouter une couche de tuile OpenStreetMap à la carte
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
}).addTo(map);

function updateMap(latitude, longitude) {
    map.setView([latitude, longitude], 12); // Définir la vue de la carte sur la nouvelle localisation
    L.marker([latitude, longitude]).addTo(map); // Ajouter un marqueur pour indiquer la localisation
}

function getLocation() {
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            var locationData = this.responseText.split(','); // Supposant que la réponse contient la latitude et la longitude séparées par une virgule
            var latitude = parseFloat(locationData[0]);
            var longitude = parseFloat(locationData[1]);
            updateMap(latitude, longitude);
        }
    };

    xhttp.open("GET", "lireGPS", true);
    xhttp.send();
}

setInterval(getLocation, 2000); // Mettre à jour la localisation GPS toutes les 2 secondes
