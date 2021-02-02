//The content of this file defines a Java class named 'ThreadBot' 
//This class inherits from the predefined Java class Thread.

public class ThreadBots extends Thread
{

	int Identity; //This integer variable will be the thread identifier
        char init_char;//This character will be used by each thread as the first letter in the password
    

	//Here we redefine the default constructor of this class.
	//By default it has no arguments, but in this example
	//We are using two arguments
	public ThreadBots() 
	{
	}
	
	
	
	public void run()
	{
		
		char[] init_char = {'i','v','t'};

		String pass = "";
		String hash = "";
		int tempPass;
		
		long startTime = System.nanoTime();
		for (int h=0; h<=2; h++) { //loop through the 3 initial chars
			for (char i='a'; i<='z'; i++) { 
				for (char j='a'; j<='z'; j++) {
					for (char k='a'; k<='z'; k++) {
						for (char l='a'; l<='z'; l++) {
							pass = pass + init_char[h];
							pass = pass + i + j + k + l;
							
							hash = (pass + ThreadAttacker.challenge);
							tempPass = hash.hashCode();
							if (tempPass == ThreadAttacker.captured) 
							{
								ThreadAttacker.found = true;
								long stopTime = System.nanoTime();
								System.out.println("Found the password in " + ((stopTime - startTime)/1000000) + " milliseconds");
							}
							pass = "";
						}
						pass = "";
					}
					pass = "";
				}
				pass = "";
			}
			long stopTime = System.nanoTime();
			System.out.println("Process " +h+ " terminated after " + ((stopTime - startTime)/1000000) + " milliseconds");
		}
					
	}

}
