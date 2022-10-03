function F = parameterfun(d,tx_p,c,f)
F = 20 * log10(d) + c * d - (tx_p - 32.45 - 20 * log10(f));

end
