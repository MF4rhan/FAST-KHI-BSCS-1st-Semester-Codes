/*
Instructions on how to install prompt-sync by running npm:
First, make sure Node JS is installed on your computer. If it is not, go to https://nodejs.org/en to install it.
If you already have Node JS installed, you can directly skip to Line: 10
After downloading and installing NodeJS, you need to add its folder address into enviroment variables.
To do that, Go to windows search bar, search up "env" and open enivroment variables.
After that, click on "enviroment variables..." button.
After that, select the variable named "Path" and then click on Edit.
After that, click on "New" and add the address of your Node JS folder, and click Ok.
Now restart your VS Code, open the terminal and type "node -v" to test. If it shows the installed version, its correctly installed.
After you have made sure that Node JS is correctly installed, go to your VS Code Terminal and Enter:
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
And then: npm install prompt-sync
It will then install the packages and you have successfully installed prompt-sync by running npm.
Use this Header file: const prompt = require('prompt-sync')(); to use the prompt function.
Now to run your program in terminal, Open the termial, type "node (your JS file name).js" and enter.
From onwards, you can press the up-arrow key on your keyboard, and click enter.
This way, The program will run in terminal like its supposed to.
But if you use "clear" to clear your terminal, you will have to do the step (line 16) again for the up-arrow key to work again.
*/
const prompt = require('prompt-sync')();
let Tasks = [];
while (true) 
{
    /*
    Also Miss, for some reason when using prompt, when you make the very first input, it reprints the entire menu for some reason.
    After the first sudden reprint, then it starts taking inputs as needed and works how its supposed to.
    I dont know why its doing that or how to fix it, so I hope you can overlook this. I suspect its a issue with the prompt itself.
    */
    let choice = prompt("\n\n1.Add Task.\n2.Remove Task.\n3.Display all Tasks.\n4.Clear all Tasks.\n5.Exit program.\nEnter your choice:  ");
    if (choice==1) 
    {
        AddTask();
    }
    else if (choice==2) 
    {
        RemoveTask();
    }
    else if (choice==3) 
    {
        DisplayAllTasks();
    }
    else if (choice==4) 
    {
        RemoveTasks();
    }
    else if (choice==5) 
    {
        process.exit(0);
    }
    else
    {
        console.log("\nInavlid Input.\n");
    }
}


function AddTask()
{
    let newtask = prompt("Enter Task: ");
    Tasks.push(newtask);
    console.log("\nTask Saved!");
}

function RemoveTask()
{
    let remove = prompt("Enter task number from the list to remove: ");
    if (remove>0 && remove<=Tasks.length) 
    {
        Tasks.splice(remove-1, 1);
        console.log("\nTask Removed Successfully.\n");  
    }
    else
    {
        console.log("\nError: Incorrect or Out of bound input.\n");
    }
    
}

function DisplayAllTasks()
{
    if(Tasks.length==0)
    {
        console.log("\nThe list is Empty.\n");
    }
    else
    {
        for (let index = 0; index < Tasks.length; index++) 
        {
            console.log(`\n${index+1}. ${Tasks[index]}`);
        }
        console.log("\n");
    }
}

function RemoveTasks() 
{
    if (Tasks.length == 0)
    {
        console.log("\nThe List is already empty.\n");
    }
    else
    {
        Tasks.length = 0;
        console.log("\nThe list has been cleared.\n");
    }
}
