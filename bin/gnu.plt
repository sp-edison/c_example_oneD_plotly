set term png
set output "result/result.png"
set xrange[-6:6]
set yrange[-1.5:1.5]
plot 'result/result.oneD' using 1:2 with lines
