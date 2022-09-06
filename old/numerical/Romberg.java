public class Romberg {
    public static double integrate(FuncOneVar func, double a, double b, double eps) {
        double h, h2, h4, h8;
        double S1, S2, S4, S8;
        double I1, I2, I4, I8;
        double R1, R2, R4;
        double Q1, Q2;
        double Romberg;
        S1 = 0.5*(func.f(a) + func.f(b);
        h = (b-a);
        do {
            h2 = h * 0.5;
            S2 = S1;
            for (double x = a + h2; x < b; x += h)
                S2 += func.f(x);
            h4 = h2 * 0.5;
            S4 = S2;
            for (double x = a + h4; x < b; x += h2)
                S4 += func.f(x);
            h8 = h4 * 0.5;
            S8 = S4;
            for (double x = a + h8; x < b; x += h2)
                S8 += func.f(x);
            I1 = S1 * h;
            I2 = S2 * h2;
            I4 = S4 * h4;
            I8 = S8 * h8;
            R1 = (4*I2 - I1) / 3;
            R2 = (4*I4 - I2) / 3;
            R4 = (4*I8 - I4) / 3;
            Q1 = (16*R2 - R1) / 15;
            Q2 = (16*R4 - R2) / 15;
            Romberg = (64*Q2 - Q1) / 63; // accurate to O(h^8)!!!
            h = h8;
            S1 = S8;
        } while (Math.abs(Q2-Q1) > eps);
        return Romberg;
            
    }

}

interface FuncOneVar {
    public double f(double x);
}

class F1 implements FuncOneVar {
    public double f(double x) { return x*x; }
}