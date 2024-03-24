//Contains configuration for racer bar chart
let chartData = {
  labels: ['Prey', 'Predator'],
  datasets: [{
    label: 'Prey',
    borderColor: 'rgba(54, 162, 255, 1)',
    borderWidth: 3,
    cubicInterpolationMode: 'monotone',
    pointRadius: 0,
    tension: 0.4,
    data: [{"data": 0, "t": 0}], //Default. Externally set as simulation is run
  },
  {
    label: 'Predator',
    borderColor: 'rgba(255, 26, 104, 1)',
    borderWidth: 3,
    cubicInterpolationMode: 'monotone',
    pointRadius: 0,
    tension: 0.4,
    data: [{"data": 0, "t": 0}], //Default. Externally set as simulation is run
  }]
};
//Insert data into config 
export default (ctx) =>
{ 
  return {
    type: 'line',
    data: chartData,
    options: {
      animation: false, //No initial animation
      parsing: {
        xAxisKey: "t",
        yAxisKey: "data"
      },
      interaction: {
        intersect: false
      },
      plugins: {
        legend: false
      },
      scales: {
        x: {
          type: 'linear'
        }
      }
    }
  }
};
