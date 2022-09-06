
public class GoldenMeanSearch {
    public static void main(String[] args) {
        double target = 2;
        System.out.println(GMS(0, 5, target, 0.01));
    }
    public static double GMS(double l, double r, double target,double delta) {
        /*
        GMS is used for find target value(min, max, constant) in typical
        function, here we use f(x) = x^2 as example. Delta is accuracy.
        */
        double a, b, s, x1, x2;
        double ratio = (Math.sqrt(5) + 1) / 2;
        while((r - l) > delta){
            a = l;
            b = r;
            s = (b - a) / ratio;
            x1 = b - s;
            x2 = a + s;
            if(Math.abs(target - f(x1)) <= Math.abs(target - f(x2))) {
                r = x2;
            } else {
                l = x1;
            }
        }
        return (l + r) / 2;
    }

    public static double f(double x) {
        return x * x;
    }
}