import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;

public class DemonstrateCachingAndDataPrefetching {


    public static void main(String[] args) throws IOException {

        //Fetching environment from command line arguments.
        String environment = args[0];

        //Integer array of predefined size (chosen randomly) and acts as the prime data for the experiment.
        int[] arr = new int[64 * 1024 * 1024];

        //Domain for the values of STEP
        int[] STEP_DOMAIN = new int[]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8096};

        //Map to store the cumulative runtime for each value of STEP.
        TreeMap<Integer, Long> map = new TreeMap<Integer, Long>();

        //Number of times the runtime is computed for each value of STEP and then is averaged out.
        int RUNS = 1000;

        for (int STEP : STEP_DOMAIN){

            //Initializing the cumulative time for each value of STEP to 0.
            map.put(STEP, (long)0);

            for(int run = 0; run < RUNS; run++){

                long startTime = System.nanoTime();

                    //Generalized Task
                    for (int i = 0; i < arr.length; i += STEP){
                        arr[i] *= 3;
                    }

                long estimatedTime = System.nanoTime() - startTime;

                long cumulativeTimeForStep = map.get(STEP);
                cumulativeTimeForStep += estimatedTime;
                map.put(STEP, cumulativeTimeForStep);
            }
        }

        FileWriter myWriter = new FileWriter(String.format("results-%1$s.csv", environment));
        myWriter.write("STEP,RUNTIME\n");
        for(Map.Entry m:map.entrySet()){

            Double averageValue = Double.parseDouble(m.getValue()+"");
            averageValue /= (double)RUNS;
            myWriter.write(m.getKey() + "," + String.format("%.02f", averageValue) + "\n");
        }
        myWriter.close();
    }
}

