# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hind.rb                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprevela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 23:10:18 by fprevela          #+#    #+#              #
#    Updated: 2019/03/16 00:32:39 by fprevela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/ruby
require "oauth2"

client = OAuth2::Client.new(ENV['HIND_UID'], ENV['HIND_SECRET'], site: "https://api.intra.42.fr")
token = client.client_credentials.get_token

if ARGV[0]
  if File.file?(ARGV[0])
    file = File.open(ARGV[0], "r").each_line do |ln|
		begin
			puts ""
			response = token.get("/v2/users/#{ln.strip}/locations")
			if response.parsed[0]["end_at"]
				puts "#{ln.strip} \u{1f44e} \u{1f44e} Not connected \u{1f44e} \u{1f44e} Last know location:"
				puts response.parsed[0]["host"]
			else
				puts "#{ln.strip} \u{1f44d} \u{1f44d} Live location \u{1f44d} \u{1f44d}"
				puts response.parsed[0]["host"]
			end
		rescue
			puts "#{ln.strip} \u{1f6ab} \u{1f6ab} Not a valid user \u{1f6ab} \u{1f6ab}"
		end
  end
	puts ""
	file.close
  else
    puts "Argument is not a file"
  end
else
  puts "usage: " + $PROGRAM_NAME + " [file]"
end
