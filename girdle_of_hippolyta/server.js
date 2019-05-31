const nodemailer = require('nodemailer');
const read = require('read');

function help(ret)
{
    console.log(`Usage: node sender.js <sender email> <receiver email> ` +
    `<subject> <email body>

    receiver email might be a comma separated list of emails\n`);
    process.exit(ret);
}

if (process.argv.length == 3 && process.argv[2] == '--help')
    help(0);
else if (process.argv.length != 6)
    help(1);

let source = process.argv[2];
let dest = process.argv[3].split(',');
let subject = process.argv[4];
let body = process.argv[5];

const auth = { user: source, pass: null };

let mailOptions = {
    from: source,
    to: null,
    subject,
    text: body
};

read({ prompt: 'Password: ', silent: true }, (err, password) => {
    if (!err)
    {
        auth.pass = password;

        let transporter = nodemailer.createTransport({
            service: 'gmail',
            auth,
        });

        dest.forEach((val) => {
            mailOptions.to = val;
            transporter.sendMail(mailOptions, (err, info) => {
                if (err)
                    console.log(`Failed to send mail to ${val}.\n${err}`);
                else
                    console.log(`Mail successfully sent to ${val}`);
            });
        });
    }
});