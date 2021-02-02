//The content of this file defines a Java class named 'ThreadBot' 
//This class inherits from the predefined Java class Thread.

public class ThreadBots extends Thread
{

	int Identity; //This integer variable will be the thread identifier
        char init_char;//This character will be used by each thread as the first letter in the password
    

	//Here we redefine the default constructor of this class.
	//By default it has no arguments, but in this example
	//We are using two arguments
	public ThreadBots(int id, char c) 
	{
		//Here we retrieve the value of the identity passed by the main class
		Identity = id;
		//Here we retrieve the value of the character passed by the main class
		init_char = c;
	}
	
	public void run()
	{

		String pass = "";
		String hash = "";
		int tempPass;
		
		long startTime = System.nanoTime();
		for (char i='a'; i<='z'; i++) {
			for (char j='a'; j<='z'; j++) {
				for (char k='a'; k<='z'; k++) {
					for (char l='a'; l<='z'; l++) {
						pass = pass + init_char;
						pass = pass + i + j + k + l;
						
						hash = (pass + ThreadAttacker.challenge);
						tempPass = hash.hashCode();
						if (tempPass == ThreadAttacker.captured) 
						{
							ThreadAttacker.found = true;
							long stopTime = System.nanoTime();
							System.out.println("Found the password in " + ((stopTime - startTime)/1000000) + " milliseconds");
						}
						if (ThreadAttacker.found==true) { this.interrupt(); }
						pass = "";
					}
					pass = "";
				}
				pass = "";
			}
			pass = "";
		}
		long stopTime = System.nanoTime();
		System.out.println("Terminated after " + ((stopTime - startTime)/1000000) + " milliseconds");
		//Here is where you write the code that should crack the password
					
	}

}
