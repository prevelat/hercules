const axios = require('axios');

let target = null;
let comp_target = null;
let count = 5;
let succeded = 0;
let comp_succeded = 0;
let requests = [];
let comp_requests = [];

const die = (msg) => {
    console.log(msg);
    process.exit(1);
};

const help = (err = false) => {
    console.log(`Usage: node cattle [ OPTIONS ] <URL>

    -c, --count <X> <URL>: Count, X requests will be performed
    -C, --compare <URL> <URL2>: Compare the benchmark between 2 URLs\n`);
    process.exit((err) ? 1 : 0);
};

const process_args = () => {
    for (var i = 2; i < process.argv.length; i++)
    {
        if (process.argv[i][0] == '-')
        {
            switch (process.argv[i])
            {
                case "-c":
                case "--count":
                    if (process.argv.length - 1 - i <= 0)
                        die(`You must specify a number for -c (--count). Try --help.`);
                    let n = Number(process.argv[++i]);
                    if (isNaN(n) || n < 1)
                        die(`Invalid number '${process.argv[i]}'.`);
                    count = n;
                    break;
                case "-C":
                case "--compare":
                    if (process.argv.length - 1 - i <= 0)
                        die(`You must specify a number for -c (--count). Try --help.`);
                    comp_target = process.argv[++i];
                    break;
                default:
                    die(`Invalid flag '${process.argv[i]}'. Try --help.`);
            }
        }
        else if (target == null)
        {
            target = process.argv[i];
        }
        else
        {
            die(`Too many arguments. Try --help.`);
        }
    }
    if (target == null)
        die(`No target specified. Try --help.`)
};

const make_request = () => {
    let start = Date.now();
    let ok = false;
    return new Promise((resolve, reject) => {
        axios.get(target)
            .then((res) => { ok = true; })
            .catch((err) => console.log(`Error: ${err}`))
            .finally(() => {
                resolve({
                    response: ok,
                    elapsed: (Date.now() - start) / 1000
                });
            });
    });
};

const present_simple = (res) => {
    let avg_time = 0;
    let fastest = Number.MAX_VALUE;
    let slowest = 0;
    res.forEach((val) => {
        avg_time += val.elapsed;
        if (fastest > val.elapsed)
            fastest = val.elapsed;
        if (slowest < val.elapsed)
            slowest = val.elapsed;
        if (val.response)
            succeded++;
    });
    avg_time /= res.length;

    console.log(`Cattle benchmark for ${target}

   	    requests made: ${count}
    	requests succeded: ${succeded} (${count / succeded * 100}%)
    average response time: ${avg_time.toFixed(3)} seconds
                  fastest: ${fastest.toFixed(3)} seconds
                  slowest: ${slowest.toFixed(3)} seconds`);
};

const present_compare = (res, com) => {
    let avg_time = [ 0, 0 ];
    let fastest = [ Number.MAX_VALUE, Number.MAX_VALUE ];
    let slowest = [ 0, 0 ];

    res.forEach((val) => {
        avg_time[0] += val.elapsed;
        if (fastest[0] > val.elapsed)
            fastest[0] = val.elapsed;
        if (slowest[0] < val.elapsed)
            slowest[0] = val.elapsed;
        if (val.response)
            succeded++;
    });
    avg_time[0] /= res.length;

    com.forEach((val) => {
        avg_time[1] += val.elapsed;
        if (fastest[1] > val.elapsed)
            fastest[1] = val.elapsed;
        if (slowest[1] < val.elapsed)
            slowest[1] = val.elapsed;
        if (val.response)
            comp_succeded++;
    });
    avg_time[1] /= res.length;

    console.log(`Cattle benchmark for ${target} -> ${comp_target}

    	    requests made: ${count}
    	requests succeded: ${succeded} (${count / succeded * 100}%) -> ${comp_succeded} (${count / comp_succeded * 100}%)
    average response time: ${avg_time[0].toFixed(3)} seconds -> ${avg_time[1].toFixed(3)} seconds
                  fastest: ${fastest[0].toFixed(3)} seconds -> ${fastest[1].toFixed(3)} seconds
                  slowest: ${slowest[0].toFixed(3)} seconds -> ${slowest[1].toFixed(3)} seconds`);
};

let _maybe_data = [ null, null ];
const maybe_call_present_compare = (name, res) => {
    
    // [0] => main data
    // [1] => compare data
    _maybe_data[(name == "main") ? 0 : 1] = res;
    
    if (_maybe_data[0] != null && _maybe_data[1] != null)
        present_compare(_maybe_data[0], _maybe_data[1]);
};

const cattle = () => {

    // Call the main target
    for (var i = 0; i < count; i++)
        requests.push(make_request());
    
    if (comp_target != null)
    {
        for (var i = 0; i < count; i++)
            comp_requests.push(make_request());
        
        Promise.all(requests)
            .then((res) => maybe_call_present_compare("main", res))
            .catch((err) => die(`Request error: ${err}`));
        Promise.all(comp_requests)
            .then((res) => maybe_call_present_compare("comp", res))
            .catch((err) => die(`Request error: ${err}`));
    }
    else
    {
        Promise.all(requests)
            .then((res) => present_simple(res))
            .catch((err) => die(`Request error: ${err}`));
    }
};

if (process.argv.length < 3)
    help(true);

process_args();
cattle();

