import java.util.Random;
import java.util.Scanner;

public class FriendlySoccerMatch implements FriendlyMatch {
	private String nameHomeTeam;
	private String nameGuestTeam;
	private int pointsHome;
	private int pointsGuest;
	public String[] commentArray = {
			" Catches the ball",
			" Deflects the ball with his fist",
			" Nods the ball away"
	};
	public String[] arr = {"","",""};
	Scanner user_input = new Scanner(System.in);
	boolean changePlayer = false;
	

	// Constructor
	public FriendlySoccerMatch(){
		pointsHome = 0;
		pointsGuest = 0;
	}
	
	@Override
	public String getHomeTeam() {
		return nameHomeTeam;
	}

	@Override
	public String getGuestTeam() {
		return nameGuestTeam;
	}

	@Override
	public int getHomePoints() {
		return pointsHome;
	}

	@Override
	public int getGuestPoints() {
		return pointsGuest;
	}

	@Override
	public String getResultText() {
		return "The friendly game ends with		\n\n"+nameHomeTeam+" - "+nameGuestTeam +" "+pointsHome+":"+pointsGuest+".";
	}
	
	

	public void startGame(Team t1, Team t2){
		nameHomeTeam = t1.getName();
		nameGuestTeam = t2.getName();
		pointsHome = 0;
		pointsGuest = 0;

		// now the game can begin; we have to create for the 
		// 90 minutes + extra time the different actions 
		Random r = new Random();
		boolean gameruns = true;
		int gameduration = 90 + r.nextInt(5);
		int time = 1;
		int nextAction = 0;
		
		// while the game runs, goals can be scored
		while (gameruns){
			nextAction = r.nextInt(15)+1;
			// Is the game over?
			if ((time + nextAction > gameduration) || (time > gameduration)){
				gameruns = false;
				break;
			}
			
			if ((time + nextAction > 45) && !changePlayer){
				changePlayer = true;
				String player_name;
				String player_motivation;
				String player_strength;
				String player_shots;
				String player_age;
				String playerChosen;
				String substituteChosen;
//				Random ran = new Random();
//				int ranNum = ran.nextInt(10);
//				System.out.println(t1.getPlayers()[ranNum]);
				System.out.println();
				System.out.println("------------------------------------------");
				System.out.println("Change player for " + t1.getName());
				System.out.println("select a player (1-10)");
				playerChosen = user_input.next();
				Player pOut = t1.getPlayers()[Integer.parseInt(playerChosen)];
				System.out.println(pOut.getName());
				System.out.println("Select a substitute player (1-3)");
				substituteChosen = user_input.next();
				Substitute sIn = t1.getSubstitute()[Integer.parseInt(substituteChosen)];
				System.out.println(sIn.getName());
				swapPlayers(t1, Integer.parseInt(playerChosen), Integer.parseInt(substituteChosen));
				System.out.println(pOut.getName() + " has been changed with "+ sIn.getName());
				System.out.println(t1.getPlayers()[Integer.parseInt(playerChosen)].getName());
				System.out.println();
				System.out.println("------------------------------------------");
//				Player p3 = new Player(player_name, Integer.parseInt(player_age), Integer.parseInt(player_strength), Integer.parseInt(player_shots), Integer.parseInt(player_motivation));
				
				
				System.out.println("------------------------------------------");
				System.out.println("------------------------------------------");
				System.out.println("Change player for team 2");
				System.out.println("Enter player name: ");
				player_name = user_input.next();
				System.out.println("Enter player motivation: ");
				player_motivation = user_input.next();
				System.out.println("Enter player strength: ");
				player_strength = user_input.next();
				System.out.println("Enter player age: ");
				player_age = user_input.next();
				System.out.println("Enter player shots: ");
				player_shots = user_input.next();
				System.out.println();
				System.out.println("------------------------------------------");
//				Player p4 = new Player(player_name, Integer.parseInt(player_age), Integer.parseInt(player_strength), Integer.parseInt(player_shots), Integer.parseInt(player_motivation));
				System.out.println("------------------------------------------");
			}
				//*******************************************
			// A new action can take place ...
			time = time + nextAction;
		
			// influence of motivation on strength:
			float strength_1 = (t1.getStrength()/2.0f) + ((t1.getStrength()/2.0f)*(t1.getMotivation()/10.0f));
			float strength_2 = (t2.getStrength()/2.0f) + ((t2.getStrength()/2.0f) * (t2.getMotivation()/10.0f));
		
			// influence of trainer on strength:
			int deviation = r.nextInt(2);
			if (strength_1 > t1.getTrainer().getExperience())
				deviation = -deviation;
			strength_1 = Math.max(1, Math.min(10, strength_1 + deviation));
			deviation = r.nextInt(2);
			if (strength_2 > t2.getTrainer().getExperience())
				deviation = -deviation;
			strength_2 = Math.max(1, Math.min(10, strength_2 + deviation));
		
			// randomly choose a player for next shot
			int shooter = r.nextInt(10);
			if ((r.nextInt(Math.round(strength_1+strength_2))-strength_1)<=0){
//				Player p = t1.getPlayers()[shooter];
//				Keeper k = t2.getKeeper();
//				int shot = p.shootsOnGoal();
//				// check if shot is saved
//				boolean goal = !k.saveShot(shot);
				Announcer( time, t1, t2, r, shooter);
//				System.out.println();
//				System.out.println(time+".Minute: ");
//				System.out.println(" Chance for "+t1.getName()+" ...");
//				System.out.println(" "+p.getName()+" shoots");
//				if (goal) {
//					pointsHome++;
//					p.addGoal();
//					System.out.println(" Goal!!! "+pointsHome+":"+
//					pointsGuest+" "+p.getName()+"("+p.getGoals()+")");
//					} 
//				else {
//					System.out.println(" "+t2.getKeeper().getName()
//					+ commentArray[r.nextInt(commentArray.length)]);
//				}
			} // IF 
			else{
//				Player p = t2.getPlayers()[shooter];
//				Keeper k = t1.getKeeper();
//				int shot = p.shootsOnGoal();
//				boolean goal = !k.saveShot(shot);
				Announcer( time, t2, t1, r, shooter);
//				System.out.println();
//				System.out.println(time+".Minute: ");
//				System.out.println(" Chance for "+t2.getName()+" ...");
//				System.out.println(" "+p.getName()+" shoots");
				
//				if (goal) {
//					pointsGuest++;
//					p.addGoal();
//					System.out.println(" GOAL!!! "+pointsHome+":"+ pointsGuest+" "+p.getName()+"("+p.getGoals()+")");
//				} 
//				else {
//					System.out.println(" "+t1.getKeeper().getName()
//					+ commentArray[r.nextInt(commentArray.length)]);
//				}
			} // else 
		}
			//WHILE
	}
	
	public void Announcer(int time, Team t, Team te, Random r, int shooter){
//		shooter = r.nextInt(10);
		Player p = t.getPlayers()[shooter];
		Keeper k = te.getKeeper();
		int shot = p.shootsOnGoal();
		boolean goal = !k.saveShot(shot);
		
		System.out.println();
		System.out.println(time+".Minute: ");
		System.out.println(" Chance for "+t.getName()+" ...");
		System.out.println(" "+p.getName()+" shoots");

		if (goal) {
			pointsGuest++;
			p.addGoal();
			System.out.println(" GOAL!!! "+pointsHome+":"+ pointsGuest+" "+p.getName()+"("+p.getGoals()+")");
		} 
		else {
			System.out.println(" "+te.getKeeper().getName()
			+ commentArray[r.nextInt(commentArray.length)]);
		}
	}
	
	
}
