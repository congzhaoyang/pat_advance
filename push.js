var shell = require('shelljs');
var inquirer = require('inquirer');

const promptList = {
    type: 'input',
    message: '输入要提交的题号',
    name: 'name',
    default: "update"
};

if (!shell.which('git')) {
  shell.echo('Sorry, this script requires git');
  shell.exit(1);
}

inquirer
  .prompt(promptList)
  .then(answer => {
    shell.exec('git add .');
    shell.exec(`git commit -m "${answer.name}"`);
    shell.exec('git push');
  });



