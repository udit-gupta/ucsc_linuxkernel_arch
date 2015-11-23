#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xfceff7dc, "module_layout" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xfecd576c, "remove_proc_entry" },
	{ 0x999e8297, "vfree" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0x85d00316, "proc_mkdir" },
	{ 0xb72397d5, "printk" },
	{ 0xb4390f9a, "mcount" },
	{ 0x73de3f10, "create_proc_entry" },
	{ 0xd6c963c, "copy_from_user" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "33797F58B38D626A4CBDDD4");
