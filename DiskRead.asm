
PROGRAM_SPACE equ 0x8000

ReadDisk:

	mov ah, 0x02
	mov bx, PROGRAM_SPACE
	mov al, 0x01
	mov dl, [BOOT_DISK]
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 0x02
	
	DiskRead_loop:
		
		push ax
		push bx
		push cx
		push dx
		
		int 0x13
		
		pop dx
		pop cx
		pop bx
		pop ax
		
		jc DiskRead_exit
		
		add bx, 512 ; write to the next 512 bytes
		inc cx ; read the next sector
		
		cmp cl, 512 ; limit to 512 sectors
		je DiskRead_exit
		
		jmp DiskRead_loop

	DiskRead_exit:
		
		pop dx
		pop cx
		pop bx
		pop ax
		
		ret

BOOT_DISK:
	db 0
