;Proiect seminar 19.01.2021
;Creat de Danila Daniel-Marian grupa 1014 
;Programul citeste de la tastatura un numar intreg pozitiv,
;dupa calculeaza prin aproximare si afiseaza partea intreaga 
;a radacinii patrate a numarului citit folosind metoda babiloniana.          

.MODEL small 
.STACK 200h 
.DATA 
mesajCitireTastatura DB 10, 13, "Introduceti un numar intreg pozitiv: $" 
mesajNuEsteNumar DB 10, 13, "Numarul introdus este formatat corect. $"
mesajPeste255 DB 10, 13, "Eroare: Numarul introdus este mai mare decat 255!$"
mesajParteIntreaga DB 10, 13, "Partea intreaga a radacinii patrate a numarului citit calculata prin aproximare este: $" 
numarCititTastatura DB 4, 3 dup(0)   
numarParteIntreaga DB 3, 2 dup(0)   

.CODE 
	citire_numar_de_la_tastatura PROC
		MOV AH, 09h 
		MOV DX, OFFSET mesajCitireTastatura 
		int 21h
		MOV AH, 0Ah 
		MOV DX, OFFSET numarCititTastatura
		int 21h
		ret
	ENDP
	
	citire_numar_in_registru PROC 
		MOV SI, 1
		MOV CL, numarCititTastatura[SI] 
	    inc CL
		xor AX, AX 
		MOV BL, 10
		adaugare_urmatoarea_cifra:
			inc SI
			mul BL
			MOV DL, numarCititTastatura[SI] 
			CMP DL, 30h
				JB nu_este_numar
			CMP DL, 39h
				JA nu_este_numar
			sub DL, 30h 
			ADD AX, DX 
			xor DX, DX
			CMP SI, CX
			JNE adaugare_urmatoarea_cifra
		CMP AX, 00FFh
			JA peste_255
		xor SI, SI
		xor BX, BX
		xor CX, CX
		ret
	ENDP
	
	partea_intreaga_a_radacinii PROC 
		MOV SI, 0
		MOV BL, 1 
		MOV CX, AX 
	    inc CX
		calcularea_radicalului:
			inc SI
			MOV AX, CX
			dec AX 
			DIV BL 
			xor AH, AH 
			ADD AX, BX 
			SHR AX, 1 
			MOV BL, AL 
			CMP SI, CX
			JNE calcularea_radicalului
		MOV AX, BX
		xor SI, SI
		xor BX, BX
		xor CX, CX
		ret
	ENDP
	
	mutare_valoare_in_variabila PROC 
		MOV BL, 10
		transfer_urmtoarea_cifra_in_variabila: 
			DIV BL 							   
			ADD AH, 30h
			MOV numarParteIntreaga[SI], AH 
			inc SI
			xor AH, AH ; 
			CMP AL, 0
			JNE transfer_urmtoarea_cifra_in_variabila
		xor AX, AX
		xor BX, BX
		ret
	ENDP
	
	afisare_parte_intreaga PROC 
		MOV AH, 09h
		MOV DX, OFFSET mesajParteIntreaga
		int 21h
		afisarea_urmatoarei_cifre:
			dec SI
			MOV AH, 02h ; 
			MOV DL, numarParteIntreaga[SI] ; 
			int 21h
			CMP SI, 0
			JNE afisarea_urmatoarei_cifre
		xor SI, SI
	    xor AX, AX
		xor BX, BX
		xor DX, DX
		ret
	ENDP

	nu_este_numar PROC 
		MOV AH, 09h
		MOV DX, OFFSET mesajNuEsteNumar
		int 21h
		CALL sfarsitProgram
		ret
	ENDP	

	peste_255 PROC
		MOV AH, 09h
		MOV DX, OFFSET mesajPeste255
		int 21h
		CALL sfarsitProgram
		ret
	ENDP
	
	sfarsitProgram PROC 
		MOV AH, 4Ch
		int 21h
		ret
	ENDP
	
StartProgram:

	MOV AX, @data 
	MOV DS, AX    

	CALL citire_numar_de_la_tastatura
	CALL citire_numar_in_registru
	CALL partea_intreaga_a_radacinii
	CALL mutare_valoare_in_variabila
	CALL afisare_parte_intreaga
	CALL sfarsitProgram
	
END StartProgram