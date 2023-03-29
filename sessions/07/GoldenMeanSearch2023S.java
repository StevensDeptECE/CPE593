public class GoldenMeanSearch2023S {
    final static double phi = (1 + Math.sqrt(5)) / 2;
    static double f(double x) { return 40 - x*x; }

    public static double goldenMean(double a, double b, double eps) {
            double s = (b-a)/phi;
            double x = b - s;
            double y = a + s;
            while (Math.abs(b-a) > eps) {
            double fx = f(x), fy = f(y);
            if (fx > fy) {
                b = y;
                s = (b-a)/phi;
                y = x;
                x = b - s;
            } else {
                a = x;
                s = (b-a)/phi;
                x = y;
                y = a + s;
            }
            System.out.println("a=" + a + " b=" + b + " x=" + x + " y=" + y);
            }            
            return (x+y)/2;
        }

    public static void main(String[]args) {
        double y=      goldenMean(-3, 8, 0.0000001);
    }
}