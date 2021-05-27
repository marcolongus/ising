export void spin_sum(uniform int vin[]) {
    
    foreach (index = 0 ... 5) {
        // Load the appropriate input value for this program instance.
        float v = vin[index];

        // Do an arbitrary little computation, but at least make the
        // computation dependent on the value being processed
        if (v < 3.)
            v = v * v;
        else
            v = sqrt(v);

        // And write the result to the output array.
        vout[index] = v;
    }
}