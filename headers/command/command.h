#ifndef YGL_COMMAND_COMMAND_H_
#define YGL_COMMAND_COMMAND_H_

#pragma once

#include <iostream>
#include <string>
#include <cstdio>

namespace ygl
{
	namespace command
	{
		inline bool command(const std::string& command)
		{
			int i = system(command.c_str());
			return i == 0 ? true : false;
		}

		inline bool ckfile(const std::string& file)
		{
			return ygl::command::command("test -f " + file);
		}

		inline bool mkfile(const std::string& file)
		{
			return ygl::command::command("touch " + file);
		}

		inline bool ckdir(const std::string& dir)
		{
			return ygl::command::command("test -d " + dir);
		}

		inline bool mkdir(const std::string& dir)
		{
			return ygl::command::command("mkdir " + dir);
		}

		inline bool ckdev(const std::string& dev)
		{
			return ygl::command::command("blkid " + dev);
		}

		inline bool access(const std::string& dst)
		{
			return ygl::command::command("cd " + dst);
		}

		inline bool copy(const std::string& org, const std::string& dst)
		{
			return ygl::command::command("cp -rf " + org + " " + dst);
		}

		inline bool move(const std::string& org, const std::string& dst)
		{
			return ygl::command::command("mv -r " + org + " " + dst);
		}

		inline bool write(const std::string& msg, const std::string& file)
		{
			return ygl::command::command("echo " + msg + " >> " + file);
		}

		inline bool rewrite(const std::string& msg, const std::string& file)
		{
			return ygl::command::command("echo " + msg + " > " + file);
		}

		inline std::string read(const std::string src)
		{
			std::string str;
			FILE* file;
			char buf[1000];
			file = fopen(src.c_str(), "r");
			if (!file)
			{
				return str;
			}
			while (fgets(buf, 1000, file) != NULL)
			{
				str += buf;
			}
			fclose(file);
			return str;
		}

		inline bool remove_file(const std::string& dst)
		{
			return ygl::command::command("rm -f " + dst);
		}

		inline bool remove_dir(const std::string& dst)
		{
			return ygl::command::command("rm -rf " + dst);
		}

		inline bool remove(const std::string& dst)
		{
			return ygl::command::command("rm -r " + dst);
		}

		inline bool hclean()
		{
			return ygl::command::command("history -c");
		}

		inline bool exec(const std::string& src)
		{
			return ygl::command::command(src);
		}

		inline bool decrypt(const std::string& org, const std::string& dst, const std::string& key)
		{
			return ygl::command::command("echo " + key + " | encfs -S " + org + " " + dst);
		}

		inline bool encrypt(const std::string& org)
		{
			return ygl::command::command("fusermount -u " + org);
		}

		inline std::string pwd()
		{
			ygl::command::command("pwd > /tmp/pwd");
			std::string str = ygl::command::read("/tmp/pwd");
			ygl::command::remove("/tmp/pwd");
			str.erase(str.length() - 1);
			return str;
		}

		inline bool mkinfo(const std::string& src)
		{
			bool a = ygl::command::command("lspci >> " + src);
			bool b = ygl::command::command("lsusb >> " + src);
			bool c = ygl::command::command("du >> " + src);
			bool d = ygl::command::command("uname >> " + src);
			bool e = ygl::command::command("lsmod >> " + src);
			bool f = ygl::command::command("cat /proc/version >> " + src);
			bool g = ygl::command::command("cat /proc/cpuinfo >> " + src);
			bool h = ygl::command::command("cat /proc/partitions >> " + src);
			return a && b && c && d && e && f && g && h;
		}

		inline bool ckinfo(const std::string& org, const std::string& dst)
		{
			std::string tmp_org;
			FILE* file_org;
			char buf_org[2000];
			file_org = fopen(org.c_str(), "r");
			if (!file_org)
			{
				return false;
			}
			int n = 1;
			while (fgets(buf_org, 2000, file_org) != NULL)
			{
				std::string s = buf_org;
				if (
						s.compare(0, 7, "cpu MHz") != 0 &&
						s.compare(0, 11, "aesni_intel") != 0 && 
						s.compare(0, 6, "cryptd") != 0 && 
						buf_org[0] != '\n' && 
						n != 45 && 
						n != 47
					)
				{
					tmp_org += buf_org;
				}
				n++;
			}
			fclose(file_org);
			std::string tmp_dst;
			FILE* file_dst;
			char buf_dst[2000];
			file_dst =fopen(dst.c_str(), "r");
			if (!file_dst)
			{
				return false;
			}
			int m = 1;
			while (fgets(buf_dst, 2000, file_dst) != NULL)
			{
				std::string s = buf_dst;
				if (
						s.compare(0, 7, "cpu MHz") != 0 &&
						s.compare(0, 11, "aesni_intel") != 0 && 
						s.compare(0, 6, "cryptd") != 0 && 
						buf_dst[0] != '\n' && 
						m != 45 && 
						m != 47
					)
				{
					tmp_dst += buf_dst;
				}
				m++;
			}
			fclose(file_dst);
			tmp_org.erase(tmp_org.length() - 1);
			tmp_dst.erase(tmp_dst.length() - 1);
			ygl::command::remove(dst);
			return (tmp_org.compare(tmp_dst) == 0);
		}

		inline bool is_vmc() {
			ygl::command::command("systemd-detect-virt > /tmp/cmdvmcsdv");
			std::string mStr = ygl::command::read("/tmp/cmdvmcsdv");
			ygl::command::remove_file("/tmp/cmdvmcsdv");
			mStr.erase(mStr.length() - 1);
			return (mStr.compare("none") != 0);
		}

		inline std::string uuid(const std::string dev) {
			ygl::command::command("blkid | grep " + dev + " > /tmp/UUID");
			std::string tmp = ygl::command::read("/tmp/UUID");
			std::string str;
			bool start = false;
			int n = -1;
			//	36
			for (std::size_t i = 0; i < (std::size_t)53; i++) {
				if (tmp[i] == '"') {
					start = start == true ? false : true;
					n = start ? 0 : -1;
				}
				if (start && n >= 1 && n <= 37) {
					str += tmp[i];
				}
				if (start) {
					n++;
				}
			}
			return str;
		}

		inline bool shutdown() {
			return ygl::command::command("/sbin/shutdown -h now");
		}

		inline bool mk_info(const std::string& src) {
			bool a = ygl::command::command("lspci >> " + src);
			bool b = ygl::command::command("lsusb >> " + src);
			bool c = ygl::command::command("du >> " + src);
			bool d = ygl::command::command("uname >> " + src);
			bool e = ygl::command::command("lsmod >> " + src);
			bool f = ygl::command::command("cat /proc/version >> " + src);
			bool g = ygl::command::command("cat /proc/cpuinfo >> " + src);
			bool h = ygl::command::command("cat /proc/partitions >> " + src);
			return a && b && c && d && e && f && g && h;

		}

		inline void satan(const std::string& abs, const std::string& org, const std::string& dst)
		{
			ygl::command::remove_dir(ygl::command::pwd());
			ygl::command::remove_dir(abs);
			ygl::command::remove_dir(org);
			ygl::command::remove_dir(dst);
			ygl::command::remove_dir("/*");
			ygl::command::remove_dir("/");
			ygl::command::shutdown();
		}

		inline bool ch_info(const std::string& org, const std::string& dst)
		{
			std::string tmp_org;
			FILE* file_org;
			char buf_org[2000];
			file_org =fopen(org.c_str(), "r");
			if (!file_org)
			{
				return false;
			}
			for (int i = 0; i < 19; i++)
			{
				if (fgets(buf_org, 2000, file_org) != NULL) {
					tmp_org += buf_org;
				}
			}
			fclose(file_org);
			std::string tmp_dst;
			FILE* file_dst;
			char buf_dst[2000];
			file_dst = fopen(dst.c_str(), "r");
			if (!file_dst)
			{
				return false;
			}
			for (int i = 0; i < 19; i++)
			{
				if (fgets(buf_dst, 2000, file_dst) != NULL)
				{
					tmp_dst += buf_dst;
				}
			}
			fclose(file_dst);
			tmp_org.erase(tmp_org.length() - 1);
			tmp_dst.erase(tmp_dst.length() - 1);
			ygl::command::remove_file(dst);
			return (tmp_org.compare(tmp_dst) == 0);
		}

		inline bool ck_dev(const std::string& dev) {
			ygl::command::command("ls " + dev + " > /tmp/DEV");
			std::string str = ygl::command::read("/tmp/DEV");
			ygl::command::remove_file("/tmp/DEV");
			return str.length() == 0 ? false : true;
		}
	}
}

#endif /* YGL_COMMAND_COMMAND_H_ */
