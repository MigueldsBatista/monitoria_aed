package quicksort;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Quicksort{

    private static void swap(List<Integer> arr, int i, int j){
        int aux = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, aux);
    }

    private static int partition(List<Integer> arr, int startIndex, int endIndex){
        int pivotIndex = endIndex;

        int pivot = arr.get(startIndex);

        for (int i = endIndex; i > startIndex; i--) {
            if(arr.get(i) >= pivot){
                swap(arr, pivotIndex, i);
                pivotIndex--;
            }
        }
        swap(arr, startIndex, pivotIndex);

        return pivotIndex;
    }

    public static void quicksort(List<Integer> arr, int startIndex, int endIndex){
        if(startIndex <  endIndex){
            int pivotIndex = partition(arr, startIndex, endIndex);

            quicksort(arr, startIndex, pivotIndex-1);

            quicksort(arr, pivotIndex+1, endIndex);
        }
    }

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>(Arrays.asList(6, 5, 4, 3, 2, 1));

        System.out.println("Antes da ordenação: " + arr);

        Quicksort.quicksort(arr, 0, arr.size() - 1);

        System.out.println("Depois da ordenação: " + arr);
    }
}