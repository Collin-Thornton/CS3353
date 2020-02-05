
public class OrganizeArray {

	public static void main(String[] args) {
		if(args.length <= 0) {
			System.out.println("\n\nEnter the elements of the array as command line arguments");
			System.out.println("Exiting...");
			System.exit(0);
		}		


		int len = args.length;
		int data[] = new int[len];

		int i=0;

		System.out.println("\nData before organization: ");

		try {		
			for(String arg : args) {
				data[i++] = Integer.parseInt(arg);
				System.out.print(arg + ' ');
			}
			System.out.println();
		} catch(NumberFormatException nfe) {
			System.out.println("Array data must be integers");
			System.out.println("Exiting...");
			System.exit(0);
		}
 
		organize(data);

		System.out.println("Data after organization: ");
		for(int value : data) System.out.print(Integer.toString(value) + ' ');

		System.out.println("\n\nExiting...");

		System.exit(0);
	}

	private static void organize(int[] data) {
		organize(data, 0, 1);
		return;
	}

	private static void organize(int[] data, int index, int swap) {
		if(swap == data.length) return;

		if(data[index] % 2 == 0) {			// if data is even, go to the next
			organize(data, ++index, swap);
			return;
		}

		if(data[swap] % 2 == 0) {			// if data is odd and swap even, swap and increment both
			int tmp = data[swap];
			data[swap] = data[index];
			data[index] = tmp;
			organize(data, ++index, ++swap);
			return;
		}

		organize(data, index, ++swap);			// otherwise increment swap
		return;
	}
}
