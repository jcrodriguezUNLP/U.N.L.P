public class MinMaxProm {
    private int min ;
    private int max ;
    private double prom ;

    // Constructor
        public MinMaxProm() {
        }

        public MinMaxProm( int min , int max , double prom ) {
            this.min = min ;
            this.max = max ;
            this.prom = prom ;
        }
    //

    // Getters
        public int getMin() { return( min ) ; }
        public int getMax() { return( max ) ; }
        public double getProm() { return( prom ) ; }
    //

    // Setters
        public void setMin( int min ) { this.min = min ; }
        public void setMax( int max ) { this.max = max ; }
        public void setProm( double prom ) { this.prom = prom ; }
    //    

    // Métodos
        public static MinMaxProm calculateWithReturn( int[] array ) {
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;
            int sum = 0;

            for (int value : array) {
                if (value > max) max = value;
                if (value < min) min = value;
                sum += value;
            }

            double average = (double) sum / array.length ;
            return new MinMaxProm( max , min , average ) ;
        }

        public static void calculateWithParameter( int[] array , MinMaxProm minMaxProm ) {
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;
            int sum = 0;

            for (int value : array) {
                if (value > max) max = value;
                if (value < min) min = value;
                sum += value;
            }

            double average = (double) sum / array.length ;
            minMaxProm.setMax( max ) ;
            minMaxProm.setMin( min ) ;
            minMaxProm.setProm( average ) ;
        }

        public static void calculateWithPrint( int[] array ) {
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;
            int sum = 0;

            for (int value : array) {
                if (value > max) max = value;
                if (value < min) min = value;
                sum += value;
            }

            double average = (double) sum / array.length ;
            System.out.println( "\n" + Sangria.sangria( 1 ) + "max: " + max ) ;
            System.out.println( "\n" + Sangria.sangria( 1 ) + "min: " + min ) ;
            System.out.println( "\n" + Sangria.sangria( 1 ) + "prom: " + average ) ;
        }

        @Override
        public String toString() {
            String texto = "" ;

            texto += ( "\n" + Sangria.sangria( 1 ) + "min: " + min ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "max: " + max ) ;
            texto += ( "\n" + Sangria.sangria( 1 ) + "prom: " + prom ) ;

            return( texto ) ;
        }
    //
}