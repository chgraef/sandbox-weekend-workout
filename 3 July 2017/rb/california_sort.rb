
# Exercise taken from the "Algorithms (IVth edition)"
# by Robert Sedgewick and Kevin Wayne.

# Implement a method, that sorts strings according to the
# the following order of characters:
#
# R W Q O J M V A H B S G Z X N T C I E K U P D Y F L
#
# The order California used in the 2003 gubernatorial election.
#

# frozen_string_literal: true

module Utils
  module_function

  def california_sort(ary_of_s)
    raise ArgumentError, '"ary_of_s" cannot be nil.' if ary_of_s.nil?

    unless ary_of_s.kind_of?(Array)
      raise ArgumentError,
        '"ary_of_s" must be of type Array. Given: #{ary_of_s.class}'
    end

    ary_of_s.each do |item|
      unless item.kind_of?(String)
        raise ArgumentError, %Q("#{item}" must be of type String)
      end

      unless /^[A-Za-z]*$/ =~ item
        raise ArgumentError,
          %Q("#{item}" may only contain alphabetic characters)
      end
    end

    expected_order = 'RWQOJMVAHBSGZXNTCIEKUPDYFL'.split(//).freeze
    value_lookup   = expected_order.zip(0...expected_order.size).to_h.freeze

    ary_of_s.sort do |left, right|
      value_lookup[left[0...1].upcase] <=> value_lookup[right[0...1].upcase]
    end
  end
end

