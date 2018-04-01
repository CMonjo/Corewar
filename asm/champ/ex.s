#
# zork.s for corewar
#
# Bob Bylan
#
# Sat Nov 10 03:24;30 2081
#
# sans pourcentage = indirecte = 2 bytes : code binaire : 11
# avec pourcentage = direct = 4 bytes : code binaire : 10
# registre = registre = 1 bytes : code binaire : 1
# attention on peut mettre des commentaires sur les lignes
#gestion de plusieurs .s, gestion de fichier sans le .s

.name	"zork"
.comment "just a basic living prog"

l2:
sti r16, %1234, %1
and r16, %0, r1
live:
live %1
st	r16,400
zjmp %:live
