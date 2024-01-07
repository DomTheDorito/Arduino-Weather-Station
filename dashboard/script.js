/*
Private Open Source License 1.0 Copyright 2024 Dominic Hord

https://github.com/DomTheDorito/Private-Open-Source-License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the “Software”), to deal in the Software without limitation 
the rights to personally use, copy, modify, distribute, and to permit persons to whom the Software 
is furnished to do so, subject to the following conditions:

1. The above copyright notice and this permission notice shall be included in all copies or substantial 
portions of the Software.

2. The source code shall not be used for commercial purposes, including but not limited to sale of the 
Software, or use it products intended for sale, unless express writen permission is given by the source creator.

3. Attribution to source work shall be made plainly available in a reasonable manner.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED 
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN THE SOFTWARE.
THIS LICENSE MAY BE UPDATED OR REVISED, WITH NOTICE ON THE POS LICENSE REPOSITORY.
*/


// Define chart variables
let lightChart, humidityChart, tempChart, pressureChart;

// Initialize charts
function initCharts() {
    lightChart = new Chart(document.getElementById('lightChart').getContext('2d'), {
        type: 'line',
        data: {
            labels: [],
            datasets: [{
                label: 'Light',
                data: [],
                borderColor: 'orange',
                borderWidth: 1,
                fill: false
            }]
        }
    });

    humidityChart = new Chart(document.getElementById('humidityChart').getContext('2d'), {
        type: 'line',
        data: {
            labels: [],
            datasets: [{
                label: 'Humidity (%)',
                data: [],
                borderColor: 'blue',
                borderWidth: 1,
                fill: false
            }]
        }
    });

    tempChart = new Chart(document.getElementById('tempChart').getContext('2d'), {
        type: 'line',
        data: {
            labels: [],
            datasets: [{
                label: 'Temperature (°C)',
                data: [],
                borderColor: 'red',
                borderWidth: 1,
                fill: false
            }]
        }
    });

    pressureChart = new Chart(document.getElementById('pressureChart').getContext('2d'), {
        type: 'line',
        data: {
            labels: [],
            datasets: [{
                label: 'Pressure (hPa)',
                data: [],
                borderColor: 'green',
                borderWidth: 1,
                fill: false
            }]
        }
    });
}

// Fetch data from 172.16.0.12 and update the dashboard
function fetchData() {
    fetch('YOUR.ESP.IP.ADDRESS') // Replace 'data' with your actual API endpoint
        .then(response => response.json())
        .then(data => {
            updateDashboard(data);
            updateCharts(data);
            updateCurrentConditions(data);
        })
        .catch(error => console.error('Error fetching data:', error));
}

// Update dashboard with new data
function updateDashboard(data) {
    document.getElementById('lightValue').innerText = data.light;
    document.getElementById('humidityValue').innerText = `${data.humidity}%`;
    document.getElementById('tempValue').innerText = `${data.temp} °C`;
    document.getElementById('pressureValue').innerText = `${data.pressure} hPa`;
}

// Update current conditions with new data
function updateCurrentConditions(data) {
    document.getElementById('currentLight').innerText = data.light;
    document.getElementById('currentHumidity').innerText = `${data.humidity}%`;
    document.getElementById('currentTemp').innerText = `${data.temp} °C`;
    document.getElementById('currentPressure').innerText = `${data.pressure} hPa`;
}

// Update charts with new data
function updateCharts(data) {
    const time = new Date().toLocaleTimeString();

    // Update light chart
    lightChart.data.labels.push(time);
    lightChart.data.datasets[0].data.push(data.light);
    lightChart.update();

    // Update humidity chart
    humidityChart.data.labels.push(time);
    humidityChart.data.datasets[0].data.push(data.humidity);
    humidityChart.update();

    // Update temperature chart
    tempChart.data.labels.push(time);
    tempChart.data.datasets[0].data.push(data.temp);
    tempChart.update();

    // Update pressure chart
    pressureChart.data.labels.push(time);
    pressureChart.data.datasets[0].data.push(data.pressure);
    pressureChart.update();
}

// Fetch data initially, initialize charts, and set up interval for periodic updates
initCharts();
fetchData();
setInterval(fetchData, 5000); // Update every 5 seconds
