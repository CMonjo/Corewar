.name		"Jarvis"
.comment	"Ultron t null"

		st	r1,9
		live	%42
		live	%42
		live	%42
		fork	%:live
		fork	%:live
		fork	%:live
start:		fork	%:pack
		st	r1,9
		live	%42
		live	%42
		live	%42
		fork	%:live1
		zjmp	%:start

pack:		fork	%:live1
		zjmp	%:pack

live:		st	r1, 6
live1:		live	%42
		fork	%:live5
		fork	%:live2
		st	r1,24
		st	r1,18
		st	r1,12
		st	r1,6
         	live	%42
		live	%42
		live	%42
		live	%42
		zjmp	%-20

live2:		fork	%:live3
		st	r1,24
		st	r1,18
		st	r1,12
		st	r1,6
         	live	%42
		live	%42
		live	%42
		live	%42
		zjmp	%-20
		fork	%:start

live3:		fork	%:live4
		st	r1,24
		st	r1,18
		st	r1,12
		st	r1,6
         	live	%42
		live	%42
		live	%42
		live	%42
		zjmp	%-20

live4:		fork	%:live1
		st	r1,24
		st	r1,18
		st	r1,12
		st	r1,6
         	live	%42
		live	%42
		live	%42
		live	%42
		fork	%:live5
		fork	%:bv
		zjmp	%-20
bv:		fork	%:live
live5:		fork	%:live1
		st	r1,24
		st	r1,18
		st	r1,12
		st	r1,6
		live	%42
		live	%42
		live	%42
		live	%42
		fork	%:live
		zjmp	%-20
